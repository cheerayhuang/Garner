#include <iostream> 

using namespace std; 


template <typename T> 
class A {

    public: 

        A() { cout << "A()" << endl; } 
        void func() 
        {
            cout << sizeof( ::A<T>()) << endl ;
            typename A<T>::A();
        }
};


int main()
{
    A<int> a; 

    a.func(); 

    return 0; 
}
