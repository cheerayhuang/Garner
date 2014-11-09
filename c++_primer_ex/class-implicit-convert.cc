#include <iostream> 

using namespace std; 

class A {
    public:
        operator int() { return 5; } 
};

class B {
    public:
        B() = default;
        B(int) {}
};

int main() {
    A a;

    // one step is ok.
    B b = static_cast<int>(a);
    B b1 = static_cast<B>(a);
    // two steps is forbidden.
    //B b = a;
    
    // or don't use implicit conversion
    B b2 = static_cast<B>(static_cast<int>(a));

    return 0;
}

