#include <iostream>

template <typename T>
class A {
public:
    A(T&&, T&&) {}
};

A(int) -> A<size_t>;


template <typename T, std::size_t size>
struct array {
    T arr[size];
};

template<typename T, typename... Args>
array(T, Args...) -> array<T, sizeof...(Args)+1>;

template <typename T = int>
struct X{
    T arr[10];
};

struct XClass {
    X<> x;
};


template <typename T, template<typename T2> typename T3 = X>
struct C {
    T3<T> arr;
};

template<template<typename T> typename... Ts>
struct Cn {

};

int main() {
    A a(1, 1);

    //A a1(1, 1.0f);
    //

    array<int, 3> arr{1,2,3};

    array arr2{1,2, 3, 4};

    C<int, X> c;

    C<double> c2;

    Cn<X, X, X> cn;

    return 0;
}
