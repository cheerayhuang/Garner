#include <iostream>

#include "func_temp.h"
#include "class_temp.h"

int main() {

    func(1.5);
    func('c');
    func("aac");
    func(4);

    N::X1<int> x1;
    x1.func1();
    //x1.func2();

    N::X1<double> x2;
    x2.func1();
    x2.func2();

    N::X2<char> x3;
    x3.func1();
    x3.func3();

    return 0;
}
