#include <iomanip> 
#include <sstream> 
#include <string>
#include <iostream> 

using namespace std; 


int main()
{
    istringstream is("one 2.34 five"); 

    string str; 

    is >> setw(2) >> str; 

    cout << str << endl; 

    int i; 
    is >> setw(2) >> str; 

    cout << str << endl; 

    if(is.fail()) 
        cout << "read int failed!" << endl; 

    is >> setw(2) >> i; 

    cout << i << endl; 

    return 0; 
}
