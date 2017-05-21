#include <iostream>

using namespace std;


void friend_func();

struct Base {
    friend void friend_func() {}

    void func() {
        friend_func();
    }
};

/*void Base::func() {
    friend_func();
}*/

void func() {
    friend_func();
}


int main() {

    return 0;
}
