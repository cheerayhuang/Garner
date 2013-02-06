#include <algorithm> 
#include <vector> 

#include <iostream> 
#include <cassert> 

using namespace std; 

int main()
{
    int a[] = {10, 20, 30}; 

    const size_t size = sizeof(a) / sizeof(a[0]); 

    int b[size]; 

    copy(a, a+size, b); 

    for(int i = 0; i < size; ++i)

        cout << b[i] << endl; 

    assert(equal(a, a+size, b)); 

    vector<int> v1(a, a+size); 
    vector<int> v2(size); 

    copy(v1.begin(), v1.end(), v2.begin()); 
    assert(equal(v1.begin(), v1.end(), v2.begin())); 

    return 0; 
}

