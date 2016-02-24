/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: ex13_14.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 02-24-2016 10:47:18
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

class num {
public:
    int no;

public:
    num(): no(1234) {}
    num(const num& n2) : no(5678) {}

    num& operator=(const num&) = default;
};

void f (const num& s) { cout << s.no << endl; }


int main() {

    num a, b = a, c =b;
    f(a); f(b); f(c);

    return 0;
}

