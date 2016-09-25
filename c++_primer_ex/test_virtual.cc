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


int k;
class Defined {
public:

    void func() { ++k; }
    //using myint = int;
    //myint i;

};

template<typename T>
class A_tmp {
public:
    virtual T func(T a) {}
};

template <typename T>
class B_tmp : public A_tmp<int> {

    public:
        using A_tmp<int> :: func;
        virtual int func(int a, int) { cout << "int a" << endl; }

        virtual T another_v_func(const T&) {}

        /*template<typename X>
        virtual X& bar(const X&) {

        }*/

};

class C_tmp : public B_tmp<double> {
    public:

        double another_v_func(const double&) override { cout << "C::another_v_func" <<endl; }

};



int main() {

    B b;

    A a = b;

    A_tmp<int> *base = new B_tmp<double>();

    base->func(5);
    //base->func(5, 6);

    //base->another_v_func();

    B_tmp<double> *base2 = new C_tmp;

    base2->func(10);
    base2->func(10, 11);
    base2->another_v_func(10.0f);

    return 0;
}
