#include <cstddef> 
#include <iostream> 

using namespace std; 


template<typename T, size_t R> 
void init1(T a[R]) 
{

    // a pointer,  the result is 4.
    cout << sizeof(a) << endl; 
}

template<typename T, size_t R> 
void init2(T (&a)[R]) 
{
    
    // when pass a array parameter by reference, it can't transform to pointer. 
    // the result is 20
    cout << sizeof(a) << endl; 
}

int main()
{
    int a[5]; 

    // and here, "by value" can't deduce the dimension. 
    init1<int, 5>(a); 

    // "by reference", it can deduce the dimension.
    init2<int>(a);

    return 0; 
}

