#include <iostream> 

using namespace std; 

template <typename T> 
class A {

public:

    void func1() { cout << "func1 " << endl; }
    void func2() { cout << "func2 " << endl; } 

    // in gcc, you can use virtual function in template... NB!
    virtual void func3() {} 
};



template <typename T> 
class A<T*> {

    public:

    void func1() { cout << "func1 pointer version" << endl;} 
    void func2() { cout << "func2 pointer version" << endl;} 

    virtual void func3() { }
};

template<> 
void A<float> :: func2() { cout << "func2 full specialization" << endl; } 

template <> 
class A<void*> {
     virtual void func() {}; 
};


template <>
class A<short> : public A<void*> {
};

int main()
{
    cout << "a:" << endl;
    A<int> a; 

    a.func1(); 
    a.func2(); 

    cout << "b:" << endl;
    A<double*> b;

    b.func1(); 
    b.func2();

    cout << "c:" << endl; 
    A<float*> c; 
    c.func1(); 
    c.func2();

    cout << "d:" << endl; 
    A<float> d; 
    d.func1(); 
    d.func2(); 

    cout << "e:" << endl;
    A<void*> e; 
 // error! e has no member named "func1" or "func2"   
 //   e.func1(); 
 //   e.func2(); 

    return 0;
}

