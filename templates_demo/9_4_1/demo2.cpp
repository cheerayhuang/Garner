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
     * here, I test to check a var defined by D, is a unqualified dependant name. The answer is YES. since if i write twice: 
     * D d_field; 
     * D d_field; 
     * the g++ will report re-definition error. so, that demonstrates  it will be checked in template definition. 
     *
     * and if I give a type "double*", an error will be report in func2, it prove that "d_field" will be check in template instantiation. 
     *
     * In addition,  I change that as below, the g++ will compile it ok. 
     * It prove that gcc works in twice-lookup mode based on c++ standard... if the name is qualified dependant name, it will only be checked in template instantiation.
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

int main() 
{
   // Derived <double> derived; 
    /*derived.func(); 

    cout << derived.base_field << endl; */

    return 0; 
}
