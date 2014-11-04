#include <iostream> 

using namespace std; 

class Constexpr {

private: 
    int i; 
    char c;
    double d;

public: 

    constexpr Constexpr() : i(1), c(48), d(3.5d) {
    }

    constexpr Constexpr(int val): i(val), c(48), d(3.5d) {}

    constexpr operator int() {
        return i;
    }

};

constexpr int func(int i) {
    return i;
}

int main() {
    constexpr Constexpr c = 5;

    int i = 10; 
    //constexpr Constexpr c2 = i;

    constexpr int j = c;

    //constexpr int k = func(i);
    
    return 0;
}

