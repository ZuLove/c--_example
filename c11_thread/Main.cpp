#include <thread>
#include <mutex>
#include <iostream>
#include <condition_variable> 

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

std::once_flag flag;
void do_something(){
    std::call_once(flag, [](){std::cout << "Call once" << std::endl; });
    std::cout << "Called each time" << std::endl;
}

struct BoundeBuffer 
{
    int* buffer;
    int capacity;
    int front;
    int rear;
    int count;

    std::mutex lock;

    std::condition_variable not_full;
    std::condition_variable not_empty;

    BoundeBuffer(int capacity) :capacity(capacity), front(0), rear(0), count(0){
        buffer = new int[capacity];
    }

    ~BoundeBuffer(){
        delete[] buffer;
    }

    void deposit(int data){
        std::unique_lock<std::mutex>l(lock);
        not_full.wait(l, [this](){return count != capacity; });
        buffer[rear] = data;
        rear = (rear + 1) % capacity;
        ++count;

        not_empty.notify_one();
    }

    int fetch(){
        std::unique_lock<std::mutex>l(lock);

        not_empty.wait(l, [this](){return count != 0; });

        int result = buffer[front];
        front = (front + 1) % capacity;
        --count;

        not_full.notify_one();
        return result;
    }
};

void consumer(int id, BoundeBuffer& buffer)
{
    for (int i = 0; i < 50; ++i)
    {
        int value = buffer.fetch();
        std::cout << "Consumer " << id << " fetched " << value << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }
}
void producer(int id, BoundeBuffer& buffer)
{
    for (int i = 0; i < 75;++i)
    {
        buffer.deposit(i);
        std::cout << "Produced " << id << " produced " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

struct Counter{
    int value;
    void increment(){
        ++value;
    }
    void decrement(){
        --value;
    }
    int get(){
        return value;
    }
};
#include <atomic>

struct AtomicCounter {
    std::atomic<int> value;

    void increment(){
        ++value;
    }

    void decrement(){
        --value;
    }

    int get(){
        return value.load();
    }
};
int main(){
//     Complex complex;
//     complex.both(32, 23);
//     std::thread t1(work);
//     std::thread t2(work);
//     t1.join();
//     t2.join();
//     std::thread t1(do_something);
//     std::thread t2(do_something);
//     std::thread t3(do_something);
//     std::thread t4(do_something);
//     t1.join();
//     t2.join();
//     t3.join();
//     t4.join();
//     BoundeBuffer buffer(200);
//     std::thread c1(consumer, 0, std::ref(buffer));
//     std::thread c2(consumer, 1, std::ref(buffer));
//     std::thread c3(consumer, 2, std::ref(buffer));
//     std::thread p1(producer, 0, std::ref(buffer));
//     std::thread p2(producer, 1, std::ref(buffer));
// 
//     c1.join();
//     c2.join();
//     c3.join();
//     p1.join();
//     p2.join();
    system("pause");
    return 0;
}