#include <iostream>
#include <type_traits>

template <typename T>
struct B {
    using type = typename T::type;   
};

template <typename T>
void func(double) {
    std::cout << "func(double)" << std::endl;
}

template <typename T, typename U = typename T::type, typename V = typename B<T>::type>
void func(int) {
    std::cout << "func(int)" << std::endl;
}

template <typename T>
auto add(T&& a, T&& b) -> decltype(a+b) {
    return a+b;
}

template <typename T, size_t N>
struct array {
    T arr[N];
};

template <typename T, typename... Args>
array(T t, Args...) -> array<std::enable_if_t<(std::is_same_v<Args, T> &&...), T>, sizeof...(Args)+1>;


template <typename T, typename S = std::void_t<
    typename T::type, 
    decltype(std::declval<T>().value),
    decltype(std::declval<T>()-std::declval<T>())>>
auto minus(T a, T b) {
    return a-b;
}

int main() {
    struct C { using type = int; 
        int operator+(const C& c) {
            return i + c.i;
        }


        int i = 1024;
    };

    func<B<C>>(1);
    func<void>(1);

    std::cout << add(1, 5) << std::endl;

    std::cout << add(C(), C()) << std::endl;

    ::array<int, 5> arr1;
    std::copy(std::begin(arr1.arr), std::end(arr1.arr), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    ::array arr2{5, 4, 3, 2, 1};
    std::copy(std::begin(arr2.arr), std::end(arr2.arr), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    //error, B does not have operator+
    //std::cout << add(B(), B()) << std::endl;
    //
    struct D {
        using type = int;
        type i;

        auto operator-(const D& d) {
            return i - d.i;
        }

        //float value() { return .0; };
        private:
        float value;
    };
    // error
    //minus(int(), int(3));
    //

    std::cout << minus(D(), D()) << std::endl;

    return 0;
}
