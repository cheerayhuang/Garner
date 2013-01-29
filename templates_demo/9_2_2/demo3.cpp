#include <iostream> 

using namespace std; 

namespace N{

    class X {

    };

    template <typename T> void select(X*); 
}

void g(N::X *xp) 
{
    N::select<int>(xp); 
}
