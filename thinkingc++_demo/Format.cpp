#include <fstream> 
#include <iostream> 

using namespace std; 

#define D(A) T << #A << endl; A; 

int main() 
{
    ofstream T("format.out"); 

    D(int i = 47;)
    D(float f = 2300114.414159;) 

    const char *s  = "Is there any more?"; 

    D(T.setf(ios::showbase);) 
    D(T.setf(ios::uppercase);) 
    D(T << s << endl;)
    D(T << i << endl;)
    D(T.setf(ios::hex, ios::basefield);) 
    D(T << i << endl;) 
    D(T.setf(ios::oct, ios::basefield);)
    D(T << i << endl;) 

    D(T.setf(ios::dec, ios::basefield);)
    D(T.fill('^');) 
    D(T << T.width(20) << endl;)
    D(T.width(21);)
    D(T << i << endl;) 

    D(T << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);) 
    D(T << f << endl;) 
    D(T.unsetf(ios::fixed);)
    D(T << f << endl;)
    D(T.precision(15);) 
    D(T << f << endl;) 

    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)

    D(T.setf(ios::scientific, ios::floatfield);)
    D(T.setf(ios::showpoint);)
    D(T << f << endl;)

    D(T << i << endl;)
    return 0; 
}

