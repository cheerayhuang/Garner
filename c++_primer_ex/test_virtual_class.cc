/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_virtual_class.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-17-2016 19:40:30
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

class A {
    virtual void func() { }
    int i = 10;
};

class B : public A {
    int i = 11;
};

class C : public A {
    int i = 11;
};

class D : public B, public C {
};



int main() {

    /*unsigned int i = 0x1012;
    cout << hex << (int) *reinterpret_cast<uint8_t *>(&i) << endl;
    cout << hex << (int) *(reinterpret_cast<uint8_t *>(&i)+1) << endl;
    */

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;

    A a;

    B b;

    C c;

    D d;

    int *p = reinterpret_cast<int*>(&c);

    cout << "C:" << endl;
    cout << hex << *p << endl;
    cout << hex << *(p+1) << endl;
    cout << hex << *(p+2) << endl;
    cout << hex << *(p+3) << endl;

    p = reinterpret_cast<int*>(&b);


    cout << "B:" << endl;
    cout << hex << *p << endl;
    cout << hex << *(p+1) << endl;
    cout << hex << *(p+2) << endl;
    cout << hex << *(p+3) << endl;
    cout << hex << *(p+4) << endl;
    cout << hex << *(p+5) << endl;
    cout << hex << *(p+6) << endl;
    cout << hex << *(p+7) << endl;


    cout << "D:" << endl;
    p = reinterpret_cast<int*>(&d);
    cout << hex << *p << endl;
    cout << hex << *(p+1) << endl;
    cout << hex << *(p+2) << endl;
    cout << hex << *(p+3) << endl;
    cout << hex << *(p+4) << endl;
    cout << hex << *(p+5) << endl;
    cout << hex << *(p+6) << endl;
    cout << hex << *(p+7) << endl;
    cout << hex << *(p+8) << endl;
    cout << hex << *(p+9) << endl;
    cout << hex << *(p+10) << endl;
    cout << hex << *(p+11) << endl;

    return 0;
}


