/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: demo_hide.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 02-24-2016 12:49:46
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

class A {
    public:
        void func(int) {cout << "func(int)" << endl; }
};

class B : public A {

    public:
        using A::func;
        void func(short) {cout << "func(short)" << endl; }

};

int main() {

    B b;

    int i = 10;
    b.func(i);

    b.A::func(i);

    return 0;
}
