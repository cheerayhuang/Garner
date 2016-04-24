#include <iostream>

using namespace std;

class A {
    public:
        void func() { cout << "func()" << endl; }
        void func(int) { cout << "func(int)" << endl; }
        void func(double) { cout << "func(doiuble)" << endl; }

        //A() = default;
        A(int) {}
};

class B : public A {
    public:
        using A::func;
        void func(A *) { cout << "func(A *)" << endl; }

        B():A(5) {}
        //B(int) {}
        B(int): A(10) {}

};

int main() {
    A a(5);
    B b;

    b.func(&a);
    b.func(1024.11d);
    b.func(1024);
    b.func();

    B b2(10);

    return 0;
}
