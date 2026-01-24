#include <iostream>
#include <concepts>

template <typename T>
concept have_type = requires(T t) {  // requires 表达式，表明后面是该表达式的内容
    typename T::type; 
    t+t;
    //{t+1} -> std::same_as<int>; 
    {t+1} -> std::integral<>; 

    t-1;

    //注意这里的区别，加 requires 关键字表达这是一个requires 子句,代表了这是一个嵌套约束，
    //要求后面的是一个约束-- 任意的常量表达式即constexpr表达式，且值为一个bool值;
    //不加 requires 关键字，则表明这是简单约束或者是符合约束里的{express;} 
    requires sizeof(T) > 4;
    //sizeof(T) > 4;
    
    // 可以执行这样形式的表达式，也就是要有run方法
    //{t.run(1)};
    t.run(1);
}; 

template <typename T>
struct X {
    void func() { std::cout << "func" << std::endl; }
};

/*
template <typename T>
    requires have_type<T> // requires 子句，要求后面是一个约束
*/
template <have_type T>
struct X<T> {
    
    void func() {
        std::cout << "func(T::type)" << std::endl;
    }
};

int main() {
    struct A { 
        using type = int; 

        A operator+(const A& a) {
            return A{i + a.i};
        }

        char operator+(const char& j) {
            return static_cast<char>(i) + j; 
        }

        short operator-(const short& j) {
            return static_cast<short>(i) - j;
        }

        void run(int) {

        }

        type i;
        char j;
    };

    struct B {
        using type = int;
    };

    X<int>().func(); 
    X<A>{}.func();
    X<B>().func();

    std::cout << int{} << int() << std::endl;

    std::cout << std::integral<int> << std::endl;
    std::cout << sizeof(A) << std::endl;
    
    return 0;
}

