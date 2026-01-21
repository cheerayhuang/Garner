#include <iostream>
#include <string>

template <typename T>
std::string s = "?";

template <typename T>
std::string s<T*> = "pointer";

template <typename T>
std::string s<T&> = "ref";

template <typename T1, typename T2>
struct X {
    void func();

    template <typename U1, size_t N = 10>
    struct Y {};
};

template <typename T1, typename T2>
void X<T1, T2>::func() {
    std::cout << "original" << std::endl;
}

template <typename T2>
struct X<void, T2> {
    void func();

    void func2();

    void func3() {
        std::cout << "<void, T2>::func3" << std::endl;
    }
};

template <typename T2>
void X<void, T2>::func() {
    std::cout << "<void, T2>::func" << std::endl;
} 

template <typename T2>
void X<void, T2>::func2() {
    std::cout << "<void, T2>::func2" << std::endl;
}

template <>
template <typename T>
struct X<int, long>::Y<T, 11> {
    int i = 1100;
};

template <typename, typename>
inline constexpr bool is_same_v = false;

template <typename T>
inline constexpr bool is_same_v<T, T> = true;


int main() {

    std::cout << s<double> << std::endl;
    std::cout << s<double*> << std::endl;
    std::cout << s<double&> << std::endl;

    X<int, double> x1; 
    x1.func();

    X<void, float> x2;
    X<void, std::string> x3;

    x2.func();
    x3.func2();
    x3.func3();

    X<int, long>::Y<double, 11> y1;
    X<int, long>::Y<double, 10> y2;

    std::cout << y1.i << std::endl;
    //std::cout << y2.i << std::endl;
    
    std::cout << is_same_v<std::string, const char *> << std::endl;
    std::cout << is_same_v<char *, const char *> << std::endl;
    std::cout << is_same_v<char *, char *> << std::endl;
    
    return 0;
}
