#include "func_temp.h"

#include <iostream>
#include <typeinfo>

template <typename T>
void func(T t) {
    std::cout << typeid(T).name() << std::endl;
}

template void func<double>(double);
template void func<>(char);
template void func(int);

// 利用全特化生成模版实例，从而完成函数定义
template <>
void func<const char *>(const char * s) {
    std::cout << typeid(s).name() << std::endl;
}
