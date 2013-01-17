#include <iostream> 

using namespace std; 


class thank {

    private :
        int n; 

    public:
        thank(int i) : n(i) {} 
       
        friend ostream& operator <<(ostream& os, thank& th) 
        {
            return os << "thank user " << th.n << endl; 
        }

};


int main() 
{
    int i = 1234; 

    thank th(10); 
    cout << i << th ; 

    // error! cause thank(10) is a temporal object, it should be const. 
    // cout << i << thank(10); 
    

    return 0; 
}
