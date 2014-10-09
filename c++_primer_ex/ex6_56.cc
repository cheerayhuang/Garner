/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_56.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-09-2014 17:04:31
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

//using FType = int (int, int);
typedef int FType(int, int);

int f1(int x, int y) {
    return x + y;
}

int f2(int x, int y) {
    return x - y;
}

int f3(int x, int y) {
    return x * y;
}

int f4(int x, int y) {
    if (y == 0) {
        return -1;
    }
    return x / y;
}

int main() {

    vector<FType*> vecf {f1, f2, f3, f4}; 
    cout << vecf.at(0)(1, 2) << endl;
    cout << vecf.at(1)(4, 3) << endl; 
    cout << vecf[2](4,3) << endl;

    for(auto i : vecf) {
        cout << i(10, 2) << endl;
    }

    vector<FType*> :: iterator iter;
    for (iter = vecf.begin(); iter != vecf.end(); ++iter) {
        cout << (*iter)(10,2) << endl;
    }

    for(decltype(f1) *i : vecf) {
        cout << i (10, 2) << endl; 
    }

    return 0;
}

