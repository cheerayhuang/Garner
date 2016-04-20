#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void Print(const T & c) {
    typename T::size_type i;

    for (i = 0; i < c.size(); ++i) {
        cout << c[i] << endl;
    }
}

template<typename T>
void Print(T&& c) {
    for (auto i = c.begin(); i != c.end(); ++i)
        cout << *i << endl;
}

class A {
    public:
        A(){}
        A(int) {};
};


template class vector<A>;
int main() {
    vector<int> v = {1, 2, 3};


    Print(v);

    Print(vector<int>(5, 5));

    return 0;
}
