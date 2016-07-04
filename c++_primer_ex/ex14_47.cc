/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex14_47.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-04-2016 23:44:33
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class I {

public:
    operator const int() { return 5; }
    operator int () const { return 6; }
};

class C {
    public:
        C(int) { cout << "c int" << endl; };
        C(double) { cout << "c double" << endl; };
};

class E {
    public:
        E(double) {cout << "e double" << endl;}
};

void func(C &&c) {

}

void func(E &&e) {

}

int main() {

    I i;

    cout << int(i) << endl;

    const I* pi = &i;

    cout << int(*pi) << endl;

//    func(10);

};


