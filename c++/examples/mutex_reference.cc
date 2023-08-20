#include <mutex>
#include <iostream>

class GlobalCounter
{
    uint64_t count;
public:
    GlobalCounter(): count(0) {}
    void increment();
};

void GlobalCounter::increment() {
    this->count += 1;
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
        template<typename F>
        void custom_increment(F custom_function)
        {
            std::lock_guard<std::mutex> locked_ins(this->lock_counter);
            custom_function(this->counter);
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

int main()
{
    globalProtectedCounter.protected_increment();
    globalProtectedCounter.custom_increment(customIncrement);

    // some invalid
    globalProtectedCounter.custom_increment(customMaliciousIncrement);
    maliciousPointer->increment();

}