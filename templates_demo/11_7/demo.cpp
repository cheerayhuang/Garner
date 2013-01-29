class A {

    friend void func(int) {} 
    friend void func(A &a) {} 
};

int main() 
{
    A a; 
    func(a);
    return 0; 
}

