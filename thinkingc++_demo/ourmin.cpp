#include "ourmin.h" 
#include <iostream> 

namespace our {
template<typename T> 
const T& min(const T& a, const T&b)
{
    std::cout << "in our min()!" << std::endl;    
    return (a < b) ? a : b;
}
};

