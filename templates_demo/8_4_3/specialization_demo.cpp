#include <iostream> 

using namespace std; 

template <typename T> 
void func(T a) {} 

template <> 
void func<>(int a) { cout << "int!" << endl; } 

template 
void func<double>(double a);


template <typename T> 
void func_in_class(T a) 
{
    cout << " func _in _class " << endl; 

}

int main()
{
    func(5); 

    func(5.01234567);

    return 0; 
}
