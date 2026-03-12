#include <iostream>
#include <thread>

#include "async_simple/coro/SyncAwait.h"
#include "async_simple/coro/Lazy.h"
#include "async_simple/coro/ConditionVariable.h"

async_simple::coro::Notifier notifier;

async_simple::coro::Lazy<> producer() {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(5s);
    std::cout << "after sleeping 5s, notifying..." << std::this_thread::get_id() << std::endl;
    notifier.notify();

    co_return;
}

async_simple::coro::Lazy<> consumer() {
    std::cout << "waiting..." << std::this_thread::get_id() << std::endl;
    co_await notifier.wait();
    std::cout << "wake up, " << std::this_thread::get_id() << std::endl;

    //co_return;
}

int main(int argc, char **argv) {
    std::cout << "hello world!" << std::endl;
    
    /*
    std::jthread c1{[]{
        consumer().start([](auto&&){});
    }};

    std::jthread c2{[]{
        consumer().start([](auto&&){});
    }};

    std::jthread p1{
        []{
            //async_simple::coro::syncAwait(producer());
            producer().start([](auto&&){});
        }};
    */

    consumer().start([](auto&&){});
    consumer().start([](auto&&){});

    producer().start([](auto&&){});

    return 0;
}
