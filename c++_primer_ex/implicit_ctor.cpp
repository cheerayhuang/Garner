#include <iostream>

//template <typename T>
class A {
public:

    /*
    A(int x) {}
    A(double x) {

    }*/

    A() = default;

    /*
    template <typename... Ts>
    A(std::initializer_list<std::common_type_t<Ts...>> li) {}
    */

    A(std::initializer_list<float> li) {}
    int i;
    float j;
    double k;

};

template <typename T>
concept signed_integer = std::is_integral_v<T> && std::is_signed_v<T>;

int main() {

    /*
    A a{1};

    A a2 = {1};
    A a3 = {1.2f};
    A a4{1.2f};
    */

    A a5{1, 1.2, 1.2f};
    A a6;
    A a7{};
    A a8 = {};

    signed_integer auto i = 1;

    auto func = [](signed_integer auto x) { return x; };

    short j = -1;
    func(j);

    return 0;
}
