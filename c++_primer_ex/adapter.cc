#include <iostream>

using namespace std;

class A {

public:
    A() =  default;
    A(const A&) = default;
    A(A&) = default;

    A& operator = (A&) = default;
    A& operator = (const A&) = default;

};

int main() {

    return 0;
}
