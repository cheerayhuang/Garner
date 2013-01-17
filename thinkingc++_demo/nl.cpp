#include <iostream> 

using namespace std; 


ostream & nl(ostream& os) 
{
    return os << "thanks!" << '\n'; 
}

// I try to overload a new operator << , with intention to support new i/o operator that has one or more arguments.
//  and use two ways to implement it. but the syntax is a little complex...
//  give a template opertor, or give a template operator << overload.


template<int n> 
ostream & nl_plus(ostream& os, int) 
{
    return os << "thanks user " << n << endl; 
}

ostream& operator <<(ostream& os, ostream& (*pf)(ostream&, int))
{
    return pf(os, 0); // 0 is a magic number
}

ostream & nl_plus(ostream& os, int i ) 
{
    return os << "thanks user " << i << endl;

}

template<int n> 
ostream& operator <<(ostream& os, ostream& (*pf)(ostream&, int))
{
    return pf(os, n);
}


int main()
{

    int i = 1234; 
    
    cout << i << "hellow world" << nl; 

//    operator<< <3> (cout << i, nl_plus);  

    cout << i << nl_plus<10>;

    operator << <12> (cout << i, nl_plus); 


    return 0; 
}


