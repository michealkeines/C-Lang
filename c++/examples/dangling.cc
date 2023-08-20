#include <thread>
#include <iostream>

struct func
{
    int& i;
    func(int& i_): i(i_){}
    void operator()()
    {
        for (unsigned j=0; j<100000;++j)
        {
            i = i + 1;
            std::cout << i <<std::endl;
        }
    }
};

int main()
{
    int state = 0;
    func my_func(state);
    std::thread my_thread(my_func);
    my_thread.join();
    std::cout << "state: " << state <<std::endl;
    return 0;
}