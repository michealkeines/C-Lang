#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Hello world in thread!\n";
}

int main()
{
    std::thread t1(hello);
    std::thread t2([](){
        std::cout << "this is from the inner loop\n";
    });
    t1.join();
}