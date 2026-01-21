#include "class_temp.h"

#include <iostream>

namespace N {
    template <typename T>
    void X1<T>::func1() {
            std::cout << "X1<T>::func1" << std::endl;
    }

    template <typename T>
    void X1<T>::func2() {
            std::cout << "X1<T>::func2" << std::endl;
    }

    template <typename T>
    void X2<T>::func1() {
            std::cout << "X2<T>::func1" << std::endl;
    }

    template <typename T>
    void X2<T>::func2() {
            std::cout << "X2<T>::func2" << std::endl;
    }
};

template void N::X1<int>::func1();
template struct N::X1<double>;
template void N::X2<char>::func1();
template void N::X2<char>::func2();

namespace N {
    template<> 
    void X2<char>::func3() {
        std::cout << "X2<char>::func3" << std::endl;
    }

};
