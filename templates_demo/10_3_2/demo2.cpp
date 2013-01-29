class MyInt {

    public : 
        MyInt(int); 
};

MyInt operator - (MyInt const &); 

bool operator > (MyInt const&, MyInt const &); 

//typedef MyInt Int; 
typedef int Int;

template <typename T> 
void f(T i)
{
    if(i > 0) {
        g(-i); 
    }
}

void g(Int) 
{
    f<Int>(42); 
}

