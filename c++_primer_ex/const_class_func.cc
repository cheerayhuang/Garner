/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: const_class_func.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 03-11-2017 22:52:00
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

class B {
    public:
        void func() {
           i;
        }
        int i;
};

class A {
    public:
        B b;

        void func() const {
            b.func();
        }
};

int main() {

    const A a = A();

    a.func();

    return 0;
}
