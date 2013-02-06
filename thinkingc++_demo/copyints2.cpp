#include <algorithm> 
#include <cstddef> 
#include <iostream>

using namespace std; 

bool gt15(int x) { return 15 < x; } 

bool replace_15 (int i) 
{
    return i > 15; 
}

int main() 
{
    int a[] = {10, 20, 30} ; 

    const size_t size = sizeof(a) / sizeof(a[0]); 

    int b[size]; 

    int c[size]; 

    int *endb = remove_copy_if(a, a+size, b, gt15); 

    replace_copy_if(a, a+size, c, replace_15, 1000); 

    int *beginb = b; 

    while( beginb != endb ) 
        cout << *beginb++ << endl; 

    cout << "c array:" << endl; 
    for(int i = 0; i < size; ++i) 
        cout << c[i] << endl; 

    replace_if(a, a+size, replace_15, 999); 

    for(int i = 0; i < size; ++i)
        cout << a[i] << endl; 

    return 0; 
}
