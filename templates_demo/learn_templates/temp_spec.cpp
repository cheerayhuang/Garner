#include <iostream>

template<typename T>
struct is_void {
    static constexpr bool value = false;
};

template<>
struct is_void<void> {
    static constexpr bool value = true;
};

template<typename T>
constexpr bool is_void_v = is_void<T>::value;

template<typename T>
struct X {
    void f() const {
        puts("f");
    }

};

template<>
struct X<int> {
    void f() const {
        puts("X<int>");
    }

    void f2() const {}

    int n;
};

template <typename T>
class Y {

    public:
    template <typename T2>
    class S{};

    template <typename T3>
    int z(T3) {
        return 1;
    }

};

template <>
template <typename T2>
class Y<void>::S {

    public:
        T2 i;

};

template <>
template <>
class Y<void>::S<int> {

    public:
        int i;
        void print() {std::cout << "Y<void>::S<int>" << std::endl;}
};

template<typename T1 = void, typename T2 = int>
Y<T1>::S<T2> ys{};

template<typename T = int, size_t N= 10>
T t = N;

int main() {

    std::cout << std::boolalpha << is_void<void>::value << std::endl;
    std::cout << is_void<int>::value << std::endl;

    std::cout << std::boolalpha << is_void_v<int> << std::endl;

    X<float> x1;
    x1.f();

    X<int> x2;
    x2.f();
    x2.f2();
    x2.n = 1024;

    Y<void>::S<double> s;
    s.i = 3.14f;
    Y<void>::S<int> s2;
    s2.print();

    
    //(ys<>).i = 3.5;
    //(ys<>).print();
    //ys<>;

    std::cout << t<double, 15> << std::endl;
    //std::cout << ((ys<void, int>).i) << std::endl; // clang 16 error

    return 0;
}
