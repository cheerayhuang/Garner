#include <typeinfo> 
#include <iostream> 

using namespace std; 

template <typename T> 
class A {
};


template class A<int>;

/*template <> 
class A<int> {
};*/


template class A<double>; 

//
// when using "by reference &", the i is constant. using "by value" the const attribute will be removed. 
template <typename T> 
//void func(T& i) 
void func(T i) 
{
    i = 10; 

    cout << i << endl; 
}


int main() 
{

    A<int> a; 

    const int s = 5; 

    func(s); 

    return 0; 
}
