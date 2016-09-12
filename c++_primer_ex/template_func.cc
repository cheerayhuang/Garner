#include <iostream>

using namespace std;


template <typename T> void func(const T& val) {
    cout << "hello world" << endl;
}

class A {

public:
    A() = default;
    ~A() = default;

    int i;

};

template <int D, A& ra>
void func2() {
    cout << D << endl;
    cout << ra.i << endl;
}


A a;

int main() {

    func(5);

    A& ra = a;

    func2<5, a>();

    return 0;
}
