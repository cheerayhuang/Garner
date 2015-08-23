/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: chapt7_test.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-13-2015 22:26:32
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

class A {
public:
    const int i;
    const int &ri;

    A() : A(10) {
    }

    A(int ii) : i(ii), ri(i) {
        cout << ri << endl;
    }
};

//aggregate class

class B {
    public:
        int i;
    public:
        int j;

};

class C {
    private:
        int i;

    public:
        int j;

    C(initializer_list<int> il) {
        for (auto tmp : il) {
            i = j = tmp;
        }
    }

    C(vector<int> il) {
        cout << "vector" << endl;
        for (auto tmp : il) {
            i = j = tmp;
        }
    }
};

constexpr int func(int i) {
    return i + 10;
}


int main() {
    A a;

    B  b = {10, 10};

    C c{1,2};

    const int k = 10;

    int f = func(k);

    int arr[k];

    constexpr int x = func(k) + 10;

    cout << f << endl;

    return 0;
}


