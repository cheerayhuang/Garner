/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: template_special.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-12-2016 11:33:48
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;


template <typename T>
void func(T t) {
    cout << "T" << endl;
}

template <typename T>
void func(T *t ) {
    cout << "T*" << endl;
}


// special template can't affect overload.
template <>
void func<const char>(const char *t) {
    cout << "const char *" << endl;
}

template <typename T, typename C>
class A {

public:
    T i;
    C j;

    A() { cout << "A<T, C>" << endl;}

};

template <typename T>
class A<T, double> {
public:
    T i;
    double k;

    A() {cout << "A<T, double> " << k << endl;}
};

template <>
class A<int, double> {

        public:
        A() {cout << "A<int, double>" << endl; }

};


int main() {

    const char * str = "hello";

    func(str);

    A<int, double> a;

    return 0;
}


