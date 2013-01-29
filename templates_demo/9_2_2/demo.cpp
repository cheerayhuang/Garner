#include <iostream>
using namespace std; 

template <typename T>
class C {

    //friend void f() {}  ;
    friend void f(C<T> const&) ;
};

class D {


    friend void o() { cout << "o func!" << endl; } 
};


void g(C<int> *p) 
{
//    f(); 
    f(*p); 
}

void h(D *d) 
{
//    o(); 

}

//void o();

int main()
{
    C<int> *p; 

    g(p); 


    D *d; 

    h(d);

    o(); 


    return 0; 
}

