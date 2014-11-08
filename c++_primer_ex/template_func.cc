#include <iostream> 

using namespace std;


template <typename T> void func(const T& val) {
    cout << "hello world" << endl;
}

int main() {

    int a = 0;

    func(5); 
    func(a);

    return 0;
}
