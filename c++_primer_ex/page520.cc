#include <iostream>

using namespace std;

struct A {
    operator short() const  { return 10; }
};


void func(int) { cout << "int" << endl; }
void func(double) {cout << "double" << endl; }

struct B {
    operator short() const { return 10; }
    operator int() const {return 11; }
};

void func2(long i) { cout <<  i << endl; }
//void func2(double) {}

int main() {

    A a;

    func(a);

    B b;

    func2(b);


    return 0;
}
