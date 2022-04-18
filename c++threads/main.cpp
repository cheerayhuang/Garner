#include <thread>
#include <iostream>

using namespace std;

void func1() {
    cout << "hello world" << endl;
}

void func2() {
    cout << "hello beijing" << endl;
}

int main() {

    thread t1(func1);
    thread t2;

    t2 = std::move(t1);

    //t2.join();

    thread t3(func2);

    //t3 = std::move(t2);
    //
    t2.join();
    t3.join();

    return 0;
}
