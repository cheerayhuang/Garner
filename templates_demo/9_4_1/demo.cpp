#include <iostream> 

using namespace std; 


template <typename T> 
class Base {

    public: 

    typedef int Di; 
};


template < typename D> 
class Derived : public Base<short> {

    public :
        
        D i; 

};

int main() 
{
    cout << sizeof( Derived<double>::i ) << endl;  

    return 0; 
}
