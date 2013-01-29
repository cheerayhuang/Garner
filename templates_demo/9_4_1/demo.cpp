#include <iostream> 

using namespace std; 


template <typename T> 
class Base {

    public: 

    typedef int D; 
};


template < typename D> 
class Derived : public Base<short> {

    public :
        
        D i; 

};


class Base2 { 
    public : 

        typedef int D; 
};


template< typename D> 
class Derived2: public Base2 { 

    public: 

    D i; 
};

class Derived3: public Base2 {

    public: 

    typedef double D; 
    D i;
};

int main() 
{
    cout << sizeof( Derived<double>::i ) << endl;  
    cout << sizeof( Derived2<double>::i ) << endl; 

    Derived3 derived3; 

    cout << sizeof(derived3) << endl; 

    return 0; 
}
