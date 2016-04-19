#include <iostream>

using namespace std;

class A {
private:
    int i;
    int j;

public:
    A() {}
    A(const A& a): i(a.i), j(a.j) { cout << "copy!" << endl; }
    A(A&& a) noexcept : i(std::move(a.i)), j(std::move(a.j)) { cout << "move!" << endl; }

    A& operator=(const A&& a) noexcept  { i = std::move(a.i); j = std::move(a.j); cout << "move! operator = " << endl; }
    A& operator=(const A& a) { i = a.i; j = a.j; cout << "copy! operator = " << endl; }

};

A GetA() {
    static A a;
    cout << "another copy happends here, and optimizied by g++" << endl;
    return a;
}

class B {
    public:
    B() {}
    B(const B& b) {cout << "copy B" << endl; }
    B(B&& b) { cout << "move B" << endl;}

    B& operator=(B b) {}
};

int main() {
    A a1;
    A a2 = a1;
    A a3 = std::move(a2);

    A a4;

    a4 = GetA();

    A a5;

    a5 = a4;

    int i=1024 ;
    int && rri = 42;

    rri = i;

    cout << rri  << endl;
    rri = 10;
    cout << i << endl;

    int &ri = i;
    const int & cri = i;

    ri = 10;
    cout << cri << endl;

    B b1;

    B b2;

    b2 = b1;
    b2 = std::move(b1);


    return 0;
}
