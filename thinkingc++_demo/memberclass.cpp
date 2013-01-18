#include <iostream> 
#include <typeinfo> 

using namespace std; 

template <typename T> 
class Outer {

public: 
    template <typename R> 
    class Inner {
    public: 
        void f(); 
    };

};

template <typename T> template <typename R>  

void Outer<T> :: Inner<R> :: f() 
{
     cout << "Outer == " << typeid(T).name() << endl; 
     cout << "Inner == " << typeid(R).name() << endl; 
     cout << "Full Inner == " << typeid(*this).name() << endl; 
}

int main() 
{
    Outer<int> :: Inner<bool> inner; 
    inner.f(); 

    return 0;
}
