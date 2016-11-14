/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ch5.1.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 11-14-2016 15:29:11
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
class Base {
public:
    template <typename T1>
    void func(T1 t) {
        cout << t << endl;
    }

    void func2() {
        cout << "hello world!" << endl;
    }
};

template<typename T>
class Devrived : public Base<T> {
public:
    void f() {
        this->func2();
    }

};

int main() {

    Base<int> b;
    b.func2();

    b.template func<const char*>("char");
    b.func<>(5);
    b.func(5.0f);

    // ch 5.2
    Devrived<int> d;
    d.f();

    return 0;
}

