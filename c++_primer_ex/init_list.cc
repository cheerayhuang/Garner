/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: init_list.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-26-2015 21:19:26
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class A {
    public:
        //A(int) {}
        //A(initializer_list<int> il) {}
        int i, j, k =4; // it equals to A():k(4) {}
        A():k(5) {}
};

int main() {
    //A a = {1, 2, 3};
    A a;

    cout << a.k << endl;

    return 0;
}



