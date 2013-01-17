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

    return 0; 
}

