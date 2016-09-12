#include <iostream>

using namespace std;

class A {

public:
    A() = default;
    A(const A&) { cout << "copy construct" << endl; }
    A(A&&) { cout << "move construct" << endl; }

    A& operator=(const A&) { cout << "copy = " << endl; return *this; }
    A& operator=(A&&) { cout << "move = " << endl; return *this; }

    void func() { cout << "hello world" << endl; }

};

A&& getA() {
    static A a;
    return std::move(a);
}


int&  GetInt() {
    static int i = 10;
    //return std::move(i);
    return i;
}

class B {
public:
    void func() & { cout << "const &&" << endl; }

    void func() && { cout << "&&" << endl; }
};

int main() {

    A a1;
    // copy
    cout << "--copy--" << endl;
    A a2 = a1;

    A a3;
    // copy in getA() and move in operator=.

    cout << "--move = --" << endl;
    a3 = getA();

    cout << "--dontknow--" << endl;
    // it is not a right-ref binding, it is a call to operator=...
    getA() = a1;

    // copy in getA() and bind to A&&, print nothing.
    A&& a4 = getA();

    cout << "--copy--" << endl;
    // copy, a4 is a lvalue.
    A a5 = a4;

    //GetInt() = 6;
    //
    B().func();

    B b;
    //b.func();

    return 0;
}
