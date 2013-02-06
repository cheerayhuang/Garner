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

    /*
     * here, I test & check a var defined by D, is a unqualified dependant name. The answer is YES. since if i write twice: 
     * D d_field; 
     * D d_field; 
     * the g++ will report re-definition error. so, that demonstrates  it will be checked in template definition. 
     *
     * and if I give a type "double*", an error will be reported in func2, it proves that "d_field" will be checked in template instantiation. 
     *
     * In addition,  I change that as below, the g++ will compile it ok. 
     * It prove that gcc works in two-phase-lookup based on c++ standard... if the name is qualified dependant name, it will only be checked in template instantiation.
     */
    D::d_field; 
    D::d_field;

    public :
        
        void func() { //base_field = 1001;  // non-qualified non-dependant name, so can't find that.  

            // so for finding it,  you can change it to dependant name (qualified also) .

            Base<D> :: base_field = 1001; 
            this->base_field = 1002; 
        }

        void func2() { d_field = 1001; } // non-qualified dependant name, find it in definition. 

 //       D d_field; 

};

struct my_type {

    static int int_var;
};

int my_type::int_var = 0; 

template <typename T> 
void func() 
{
    T:: int_var; 
    T:: int_var; 
}

int main() 
{
   // Derived <double> derived; 
    /*derived.func(); 

    cout << derived.base_field << endl; */

    func<my_type>();

    return 0; 
}
