#include <iostream>

using namespace std;


template <typename T> void func(const T& val) {
    cout << "hello world" << endl;
}

class A {
};

template <int D, A& PA>
void func2() {
    cout << D << endl;
}

A a;

static const A& ra = a;

int main() {

    func(5);

    func2<5, ra>();

    return 0;
}
