/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_static.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-16-2016 11:13:04
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class A {

public:

    static int k;
    int i;
    int j;

    void func() const {
        ++k;
    }

    A() = default;

    A(int i): i(i) {}

    A(int i, int j): A(5){}
};

int A::k = 1001;

class B : private A {
    public:
        using A::A;

        void print() {
            cout << k << j << i << endl;
        }

        //B(const B&) = delete;
        B& operator=(const B&) = delete;
};

class Pure {
    public:

        virtual void func() = 0;
};

void Pure::func() { cout << "hello world" << endl; }

class Pure_1 : public Pure {
    public:
        void func(int) {
            Pure::func();
        }
};

class No;

class Noo : public No {
};


A a(1, 1);

int main() {


    cout << a.k << a.j << a.i << endl;

    B b(1, 1);

    b.print();

    B b2(b);

    Pure_1 p;

    p.func(5);



    return 0;
}

