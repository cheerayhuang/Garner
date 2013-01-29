#include <iostream> 

using namespace std; 


template <typename T> 
class Base {

    public: 

    typedef int Di; 

    int base_field; 
};


template < typename D> 
class Derived : public Base<D> {

    D d_field; 

    public :
        
        void func() { //base_field = 1001;  // non-qualified non-dependant name, so can't find that.  

            // so for finding it,  you can change it to dependant name (qualified also) .

            Base<D> :: base_field = 1001; 
            this->base_field = 1002; 
        }

        void func2() { d_field = 1001; } // non-qualified dependant name, find it in definition. 

 //       D d_field; 

};

int main() 
{
    Derived <double> derived; 
    derived.func(); 

    cout << derived.base_field << endl; 

    return 0; 
}
