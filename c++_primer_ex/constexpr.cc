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



struct Base {
int i = 10;

Base(): i(1024) {}

operator int() {
    return i;
}

};

constexpr int func(int i) {
    return i;
}

int main() {
    int k = 5;
    //constexpr Constexpr c(k);
    Constexpr c(k);
    int i = 10;
    //constexpr int j = c;

    Base b;

    cout << b.i << endl;

    //constexpr int a[b]{1, 2, 3}; // error: because  Base is not a constexpr Class.
   // constexpr int a[c]{1, 2, 3};
    //const int arr[b] = {1};


    return 0;
}

