#include <cstddef> 
#include <iostream> 

using namespace std; 

template <typename T, size_t N = 10> 
class Array {

    T data[N]; 
    size_t count; 

public:

    Array() { count = 0; } 

    void push_back(const T& t) 
    {
        if (count < N)
            data[count++] = t; 
    }

    void pop_back() 
    {
        if (count > 0)
            --count; 
    }

    T *begin() { return data; } 
    T *end()   { return data + count; } 

};


//template <typename T, size_t N, typename U = Array<T, N> >
template <typename T, size_t N, template<typename, size_t = N> class U> // here, re-define default value!
class Container {

    U<T> seq; 

public: 

    void append(const T& t) { seq.push_back(t); } 
    T *begin() { return seq.begin();}
    T *end()   { return seq.end(); } 

};

int main()
{
    const size_t N = 100; 
    Container<int, N, Array > container; 

    for(int i = 0; i < N; ++i) {
        container.append(i); 
    }


    int *p = container.begin(); 
    while (p != container.end()) 
        cout << *p++ << endl; 

    return 0; 
}

