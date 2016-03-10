/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: page535.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-07-2016 18:26:47
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
        virtual void print(ostream &os) {os << basename; }
        Base(string s): basename(s) {}

    private:
        string basename;

};

class Derived : public Base {

    public:
        void print(ostream &os) { Base::print(os); os << " " << i; }
        Derived(int i, const string & s) : Base(s), i(i) {}

    private:
        int i;
};

class Pure {

    public :
        //virtual void func() =0;
        int i;
};


class Derived2 : private Pure {

    public :
        void func(Pure p) {
            p = *this;

        }

};

class Derived3 : public Derived2 {
    public :
        void func(Derived2 p) {
            p = *this;
        }
};

int main() {

    Base b("hello");
    Derived d(10, "world");

    Base &rb = d;

    rb.print(cout);

    Pure *p = new Pure();
    Derived2 d2;
    d2.func(*p);

    Derived3 d3;
    d3.func(d2);

    return 0;
}
