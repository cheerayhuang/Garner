#include <iostream> 
#include <typeinfo>

using namespace std; 

template <typename T> class A; 
template <typename T> void func(T i, A<T>& a);

template <typename type> 
class A {

    friend void func<type>(type i, A<type>&);
    template <typename T> 
    friend void func2(T i) {
        cout << i << endl; 
    }
    
    
private: 
    type data_;

};

template <typename T> 
void func(T i, A<T>& a) {
    cout << typeid(i).name() << endl; 
    cout << typeid(a.data_).name() << endl; 
}

template <typename T> 
void func_ref(T t) {
    t = 10;
}

int main() {

    A<int> a; 

    int i; 
    func(i, a); 
    func2(i);

    const int &t = 10;

    func_ref(t);

    return 0;
}
