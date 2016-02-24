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
#include <vector>

using namespace std;

class A {
    public:
        A(int) { cout << "hello A()" << endl; }
        //A(initializer_list<int> il) { cout << "hello il" << endl; }
        int i, j, k =4; // it equals to A():k(4) {}
        A():k(5) {}
};

int main() {
    A a = {1};
    //A a;

    cout << a.k << endl;
    cout << a.i << endl;

    vector<char> v_char = {'a', 'b', 'c'};
    vector<char> v_char2 = {10, 'b'};

    return 0;
}
