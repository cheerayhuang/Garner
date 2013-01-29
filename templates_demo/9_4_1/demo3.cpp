#include <iostream> 

using namespace std; 


class Base {

    public: 

    typedef int Di; 

    int base_field; 
};


template < typename D> 
class Derived : public Base {

    public :
        
        void func() { this->base_field = 1001; 
            Base :: base_field = 1003; 
        
        }
        
};

int main() 
{
    Derived <double> derived; 
    derived.func(); 

    cout << derived.base_field << endl; 

    return 0; 
}
