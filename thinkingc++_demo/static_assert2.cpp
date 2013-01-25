#include <iostream>

using namespace std; 


template <bool> 
class StaticCheck{

    StaticCheck(...) 
    {
        
    }
};

template <> 
class StaticCheck<false> {

};

#define STATIC_CHECK(expr, msg)  { \
    class Error_##msg{}; \
    sizeof((StaticCheck<expr>(Error_##msg()))); \
} \

template <typename To, typename From> 
To safe_cast(From from) {

    STATIC_CHECK(sizeof(From) <= sizeof(To), NarrowingConversion);

    return reinterpret_cast<To>(from); 
}

int main()
{

    void *p = 0; 

    int i = safe_cast<int>(p); 
    cout << "int cast ok" << endl; 

//char c = safe_cast<char>(p);  
    return 0; 
}
