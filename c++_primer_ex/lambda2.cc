/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: lamabda2.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 10:00:50
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class L {
    private:
        int &sz;

    public:
        L(int i):sz(i) {}
        void func() { sz++; }
};

int main() {
    size_t v1 = 42;

    auto f = [&v1]() mutable  ->int { if (1+1==3) {return 0;} return ++v1; };
    //v1 = 0;

    cout << f() << endl;

    cout << v1 << endl;

    using vv = decltype(v1);

    vv vv1 = -1;

    cout << vv1 << endl;

    auto f2 = [](int i) { if (i < 0) return -i; else return i; };
    auto f3 = [](int i) { if (i < 0) return "neg"; else return "pos"; };

    int k = 1;
    auto f5 = [&k]() { k++; };


    L l(v1);
    l.func();

    auto r1 = f3(5);
    string f4 = r1;

    int i;
    int &rs1 = i;
    (i) = 5;

    f4 = "hello";

    cout << v1 << endl;

    k = 100;
    f5();

    cout << k  << endl;
    f5();
    cout << k  << endl;

    return 0;
}

