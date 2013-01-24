#include <iostream> 

using namespace std; 



class A {

    private: 
        int i;
public: 

    template <typename T> 
    friend T func(T x) { cout << "hello world" << endl;} 

    friend void func2(char) { cout << "in func2" << endl; } 

};


int i = 5; 

int main()
{
    A a; 

    func(i); 

    func2('c'); 

    return 0; 
}

template <typename T> 
int func(T x) 
{
    cout << "hello world" << endl; 

}


