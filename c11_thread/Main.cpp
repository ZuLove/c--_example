#include <thread>
#include <mutex>
#include <iostream>

struct Complex 
{
    std::recursive_mutex mutex;
    int i;
    Complex() :i(0){}
    void mul(int x){
        std::lock_guard<std::recursive_mutex> guard(mutex);
        i = i*x;
    }
    void div(int x){
        std::lock_guard<std::recursive_mutex> guard(mutex);
        i /= x;
    }
    void both(int x, int y){
        std::lock_guard<std::recursive_mutex> guard(mutex);
        mul(x);
        div(y);
    }
};

std::timed_mutex mutex;

void work(){
    std::chrono::milliseconds timeout(100);
    while (true)
    {
        if (mutex.try_lock_for(timeout))
        {
            std::cout << std::this_thread::get_id() << ":do work with the mutex" << std::endl;
            std::chrono::milliseconds sleepDuration(250);
            std::this_thread::sleep_for(sleepDuration);
            mutex.unlock();
            std::this_thread::sleep_for(sleepDuration);
        }
        else{
            std::cout << std::this_thread::get_id() << ": do work without mutex" << std::endl;
            std::chrono::milliseconds sleepDuration(100);
            std::this_thread::sleep_for(sleepDuration);
        }
    }
}
int main(){
//     Complex complex;
//     complex.both(32, 23);
    std::thread t1(work);
    std::thread t2(work);
    t1.join();
    t2.join();
    system("pause");
    return 0;
}