#include <iostream> 
#include "Urand.h" 


using namespace std; 

int main()
{
    Urand<> u; 

    for(int i = 0; i < 10; ++i) 
    {
        cout << u() << endl; 
    }

    return 0;
}
