/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: try_catch.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-25-2015 20:05:46
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <initializer_list>

using namespace std;

class B {
};

class A {
    public:
        A(){}
        constexpr A(B b):a(10) {}
        A(initializer_list<int> il) {a = *il.begin();}
        int a;
        int func() {return 42;}
};

A func() {
    A a{10};

    return a;
}

struct C {
    struct {
        int i;
        int j;
    }a;
}c;

constexpr B func(B b) {
    return b;
}


int main() {
    c.a.i = 10;
    c.a.j = 100;

    try{
        try {
            vector<int>a(5,0);
            //a.resize(a.max_size()+1);
            ifstream fin("1.txt");
            fin >> a[0] >> a[1];
        }
        catch (A & a) {

            cout << a.a << endl;

        }
        catch (int &i) {
            cout << "hello world "  << i << endl;
            throw float();
        }
        catch(length_error e) {
            cout << e.what() << endl;
        }
    }
    catch (out_of_range e) {
        cout << e.what() << endl;
    }

    catch (float i) {
        cout << "hello error" << endl;
        cout << i << endl;
    }
    return 0;
}
