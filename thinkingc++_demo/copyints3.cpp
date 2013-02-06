#include <algorithm> 
#include <iostream> 
#include <iterator> 
#include <fstream> 

using namespace std; 

bool gt15(int x) { return x > 3; } 
int main()
{

    int a[] = { 1, 2, 3, 4, 5}; 

    const size_t size = sizeof(a) / sizeof(a[0]); 

    replace_copy_if(a, a+size, ostream_iterator<int>(cout, "\n"), gt15, 99); 

    fstream f("copyints3.txt", ios::in | ios::out | ios::trunc); 

    f << "1 3 47 5 84 9" << endl; 

    f.seekg(ios::beg); 

    replace_copy_if(istream_iterator<int>(f), istream_iterator<int>(), ostream_iterator<int>(cout, "\n"), gt15, 999); 


    return 0; 
}
