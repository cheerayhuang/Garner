/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_7.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-23-2014 16:41:13
 * @version $Revision$
 *
 **************************************************************************/

#include <vector>
#include <iostream> 

using namespace std;

class A {
    public:
    int a;
    public:
        A(int, int) {}
        A(initializer_list<int> il) { a = *il.begin();}
};

int main() {

    vector<int> vec(8);
    cout << vec.size() << endl; 
    
    int k = 10;
    vector<int>::reference i = k; 
    vector<int>::const_reference ci = k;

    //ci = 10;

    typedef decltype((k)) reference;
    reference rk = k;

    cout << i << endl;

    A classA{4, 5};

    cout << classA.a << endl;

    return 0;
}


