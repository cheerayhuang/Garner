#include <cstring> 
#include <iostream> 

using std :: cout; 
using std :: endl; 


template <typename T, typename R=int>
const T min(const T a, const T b) 
{
    cout << "in min, template" << endl; 
    return (a < b) ? a : b; 
}

const char* min(char* const a, char* const b) 
{
    cout << "in min, non-template" << endl; 
    return strcmp(a, b) < 0 ? a : b; 
}


template <> 
char* const  min<char*>(char* const a, char * const b) 
{
    cout << "in min, specialization" << endl; 
    return strcmp(a,b) < 0 ? a : b; 
}

// error! partial specialization is not allowed for fuction template.
/*
template <typename R=int>
const double min<double, R>(const double a, const double b) 
{
    cout << "in min, partial specialization" << endl; 
    return (a < b) ? a : b; 
}
*/


double min(double x, double y)
{
    return (x < y) ? x : y; 
}

int main() 
{
    char *s2 = "say NI-!"; 
    char *s1 = "knights who"; 

    cout << min(1,2) << endl; 
    cout << min(1.0, 2.0) << endl; 
    cout << min(1, 2.0) << endl; 
    cout << min(s1, s2) << endl; 

    cout << min<char*>(s1,s2) << endl; 
}


