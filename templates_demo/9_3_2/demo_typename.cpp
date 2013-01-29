#include <iostream> 

using namespace std; 

template <typename T> class X {

    public: 
        class Base {

            Base() {} 
            Base(int) {}
        };

        typedef int C; 
        short D; 
};


template <typename T> 
struct S: public X<T> :: Base { 

    S() : X<T> :: Base( typename X<T> ::Base(0) ) {} 

    X<T> f() {

        typename X<T>:: C *p; 
        this-> D * 5;
    }

    X<int>:: C  *pc;
};


struct U {

    typename X<int> ::C *pc;
};

int main()
{
    return 0; 
}
