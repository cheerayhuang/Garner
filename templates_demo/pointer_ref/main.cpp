#include <iostream> 
#include <typeinfo> 

using namespace std; 

template <typename type> 
void func(const type& t) {
    
    cout << "here" << endl; 
    cout << typeid(t).name() << endl; 

}

template <typename type>
void func2(const type t) {
    cout << "here!" << endl; 
    cout << typeid(t).name() << endl; 
}

int main() {

    int i; 
    int *pi = &i;

    func(pi); 
    func2(pi);

    return 0;
}

