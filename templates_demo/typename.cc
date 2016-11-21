/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: typename.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 11-21-2016 19:37:08
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

typedef int&& int_rv;

template <typename T>
class A {

public:
    A() {
        cout << "A<T>" << endl;
    }
};

template <typename T>
class A<T&> {

public:
    A() {
        cout << "A<T&>" << endl;
    }
};

template <typename T>
class A<T&&> {
    public:
        A() {
            cout << "A<T&&>" << endl;
        }
};

int main() {
    int j = 10;
    int &i = j;
    int_rv && k = 5;

    A<decltype((j))> a_int;

    A<decltype(i)> a_lr;

    A<decltype(k)> a_rr;

    return 0;
}
