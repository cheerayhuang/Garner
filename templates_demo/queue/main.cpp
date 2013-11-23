#include "main.hpp"
#include <vector> 

int main() {

    queue<int> q; 
    q.push(10);

    std::cout << q << std::endl;

    

    std::vector<int> vec(5, 1);

    queue<int> q3(vec.begin(), vec.end());
    std::cout << q3 << std::endl;

    int a[] = {1, 2, 3, 4, 5};
    queue<int> q2(a, a+5);

    std::cout << q2 << std::endl;

    queue<int> q4; 
    q4 = q3; 

    std::cout << q4 << std::endl;

    return 0;
}

