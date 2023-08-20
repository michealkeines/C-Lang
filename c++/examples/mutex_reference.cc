#include <mutex>
#include <iostream>
#include <vector>
#include <thread>

class GlobalCounter
{
    uint64_t count;
public:
    GlobalCounter(): count(0) {}
    void increment();
    uint64_t getValue();
};

void GlobalCounter::increment() {
    std::cout << "incrementing it with thread id: " << std::this_thread::get_id() << ", count: " << this->count << "\n";
    this->count += 1;
}

uint64_t GlobalCounter::getValue() {
    return this->count;
}

class ProtectedCounter
{
    private:
        GlobalCounter counter;
        std::mutex lock_counter;
    public:
        void protected_increment()
        {
            std::lock_guard<std::mutex> locked_ins(lock_counter);
            this->counter.increment();
        }

        u_int64_t getValue()
        {
            std::lock_guard<std::mutex> lock_ins(lock_counter);
            return this->counter.getValue();
        }

        template<typename F>
        void custom_increment_func(F custom_user_func)
        {
            std::lock_guard<std::mutex> lock_ins(lock_counter);
            return custom_user_func(this->counter);
        }
};

void customIncrement(GlobalCounter& counter)
{
    for(int i=1; i < 10; i++) {
        counter.increment();
    }
}

GlobalCounter* maliciousPointer;

void customMaliciousIncrement(GlobalCounter& counter)
{
    maliciousPointer = &counter;
}

ProtectedCounter globalProtectedCounter;

int main() {
    std::vector<std::thread> thread_pool;

    for (int i = 0; i < 10; i++) {
        thread_pool.emplace_back(std::thread(&ProtectedCounter::protected_increment, &globalProtectedCounter));
    }

    for (std::thread &thread : thread_pool) {
        thread.join(); // Wait for all threads to finish
    }

    std::cout << "Final value: " << globalProtectedCounter.getValue() << std::endl;

    globalProtectedCounter.custom_increment_func(customIncrement);

    std::cout << "Final value after custom increment: " << globalProtectedCounter.getValue() << std::endl;

    return 0;
}