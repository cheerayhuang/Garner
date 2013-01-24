#include <iostream> 

using namespace std; 

namespace mynamespace{

    int x; 
    int y; 

    void func(int, int); 
    
};

int main() 
{

    mynamespace::func(mynamespace::x, mynamespace::y); 

    return 0; 
}

namespace mynamespace {

    void func(int, int) 
    {
        cout << "func(int, int)" << endl; 
    }
};
