#include <iostream>
#include <thread>

class custom_thread {
    std::thread& internal_thread;
public:
    custom_thread(std::thread& t): internal_thread(t) {}

    // call join() during desctructor call
    ~custom_thread()
    {
        if(this->internal_thread.joinable())
        {
            this->internal_thread.join();
            std::cout << "thread is joined\n";
        }
    }

    // remove copy and assingment
    custom_thread(custom_thread const&)=delete;
    custom_thread& operator=(custom_thread const&)=delete;
};

struct func{
    int& i;
    func(int& _i): i(_i) {}
    func operator()(){
        std::cout << "function is called\n";
    }
};

int main()
{
    int state = 1;
    func cus_func(state);
    std::thread thread1(cus_func);
    custom_thread t1(thread1);
    std::cout << "thread is ready\n";
    return 0;
}