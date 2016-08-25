/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_virtual.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-25-2016 15:22:11
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class A {
public:
    inline A&  func(int) {
        my_int i;
        cout << "hello world!" << endl;
    }
    typedef int my_int;

    ~A() { cout << "~A()" << endl; }

};

class B : public A {
public:
    B& func(int) {
        cout << "hello chengdu" << endl;
    }

    ~B() {cout << "~B()" << endl; }


};

int main() {

    B b;

    A a = b;

    return 0;
}
