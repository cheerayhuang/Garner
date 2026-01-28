#include <iostream>

auto func() -> auto {
    return 1;
}


int main() {
    std::cout << func() << std::endl; 
    return 0;
}
