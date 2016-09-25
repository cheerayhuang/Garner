/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_operator_+.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-19-2016 23:45:05
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <functional>

using namespace std;

class A {
    public:
    int i ;

    public:
        A(int i) : i(i) {}
        A operator = (const A & a) {
            i = a.i;
            return *this;
        }
        A ();

    void run(int) { cout << "run" << endl;}
};

void func() = delete;





void func(int) {
    cout << "int" << endl;
}

void func(char) {
    cout << "char" << endl;
}

void bar() {
    func('a');
}

void f(int, int) {}
void f2(int){}

int main() {
    A a(5), b(10), c(11);

    (c = a) = b;

    cout << c.i << endl;

    bar();

    function<void(int)> fp = bind(f, 5, placeholders::_1);
    function<void(int)> fp2 = f2;
    function<void(int)> fp3 =  [](int)->void {};

    fp = bind(&A::run, &a, placeholders::_1);

    fp(5);

    return 0;
}
