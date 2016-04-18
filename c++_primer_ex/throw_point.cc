#include <iostream>

using namespace std;

class A {
    public:
        void print() { cout << "hello world" << endl; }
        int i = 1024;
};

class B {
    public:
        A* pa;
};


void func() {
    try {
        A a;
        cout << a.i << endl;
        B b;
        b.pa = &a;
        cout << &a << endl;
        cout << b.pa->i << endl;

        throw &b;

    }
    catch (B* e) {
        e->pa->print();
        cout << e->pa << endl;
        cout << e->pa->i << endl;
        throw e;
    }
}

void func2() {

    try {
        A a;
        B b;
        b.pa = &a;
        cout << &a << endl;
        cout << b.pa->i << endl;

        cout << &b << endl;

        throw b;

    }
    catch(B & b) {
        b.pa->print();
        cout << b.pa << endl;
        cout << b.pa->i << endl;

        cout << &b << endl;

        throw b;
    }
}

int main() {
    try {
        func();
    }
    catch (B* e) {
        e->pa->print();
        cout << e << endl;
        // core dump here, since a is released.
        //cout << e->pa->i << endl;
    }

    cout << "------" << endl;
    try {
        func2();
    }
    catch(B& b) {
        b.pa->print();
        cout << b.pa << endl;
        // since pa is release , the value is messy.
        cout << b.pa->i << endl;
        cout << &b << endl;
    }

    return 0;
}
