#include <iostream> 

using namespace std; 

void f(double) { cout << "f(double)" << endl; } 

template<class T> class X {

    public:
            void g() { f(1); }
};

void f(int) { cout << "f(int)" << endl; } 

int main()
{
        X<int>().g();

            return 0; 
}

