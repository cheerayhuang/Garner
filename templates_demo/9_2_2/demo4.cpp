#include <iostream> 

using namespace std; 


template <template<typename> class TT> class X {
};

template <typename T> class C {

    C *a; 
    C<void> *b; 

    X<C> c; 

};

int main() 
{

    return 0; 
}
