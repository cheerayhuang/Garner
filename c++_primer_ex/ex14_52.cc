/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: ex14_52.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-11-2016 19:57:35
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;


class SmallInt {
    public :
        SmallInt(int = 0) {}
        operator int() const { return val; }

    private:
        size_t val;
};

class LongDouble {
    public:
        LongDouble(double = 0.0) {}
        operator double() const { return 0.1;}
        operator float() const { return 0.1;}
        LongDouble operator+(const SmallInt&) { cout << "inner class +" << endl; return LongDouble(); }
};

LongDouble operator+(LongDouble&, double) {
    cout << "out class +" << endl;
    return LongDouble();
}

LongDouble operator+(const LongDouble&, const LongDouble&) {
    cout << "out class ld+ld" << endl;
    return LongDouble();
}

SmallInt operator+(const SmallInt&, const SmallInt&) { return SmallInt(); }

class A {

};

class B {
public:
    B(const A&) {cout << "b" << endl;};
};

class C {
    public:
    C(const B&) {cout << "c" << endl;};
};

void func(const C& c) {}

int main() {

    LongDouble ld;
    SmallInt si;

    ld = LongDouble(si) + ld;
    ld = ld + si;

    double d = si + SmallInt(3.14);
    d = static_cast<double>(si) + 3.14;

    A a;

    func(C(a));

    return 0;
}
