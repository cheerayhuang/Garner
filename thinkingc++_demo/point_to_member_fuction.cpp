#include <iostream> 

using namespace std; 

class A {

    private :
        void func() { cout << "hello in A::func()" << endl; } 

    public:

        void func_public() { cout << "hello in A :: func_public()" << endl; } 

        void (A::*pf_public)(); 

        A() {
            pf_public = &A::func; 
        } 


        
};

int main()
{
    A a;
    
    void (A::*pf)() = &A::func_public;

    (a.*pf)();

    (a.*(a.pf_public))();

    return 0; 
}

