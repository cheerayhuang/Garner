/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: demo_copy.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-07-2016 22:16:21
 * @version $Revision$
 *
 **************************************************************************/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class A {
    public:
        ~A() = delete;
};

int& func () {

    static int s;
    cout << s << endl;
    return s;

}

int main () {

    decltype(func()) v = func();

    v = 1024;

    func();

    return 0;

}


