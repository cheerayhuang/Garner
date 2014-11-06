#include <iostream> 

using namespace std; 

int main() {
    size_t v1 = 42;

    auto f = [&v1]()->int { if (1+1==3) {return 0;} return ++v1; };
    v1 = 0;

    cout << f() << endl;

    return 0;
}
