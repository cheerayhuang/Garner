#include "ourmin.h" 

template<typename T> 
const T& min(const T& a, const T&b)
{
    return (a < b) ? a : b;
}

