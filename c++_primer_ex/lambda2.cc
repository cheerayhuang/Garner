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


    L l(v1);
    l.func();

    cout << v1 << endl;

    return 0;
}

