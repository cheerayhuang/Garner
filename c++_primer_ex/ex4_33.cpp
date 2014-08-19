#include <iostream> 

using namespace std; 

int main() {
    int s = 0; 
    int x=17, y = 108; 

    int res; 

    res = s? ++x, ++y : (--x, --y); 

    cout << res << endl; 

    return 0;
}
