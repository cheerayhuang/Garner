/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_23.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-01-2014 11:12:32
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <iterator> 

using namespace std; 

void print(int i) {
    cout << i << endl; 
}

void print (int *beg, int *end) {
    
    for(; beg != end; ++beg) {
        cout << *beg << ' ';
    }
    cout << endl;
}

void print(int (&j)[2]) {

    for (decltype(j[0]) ele : j) {
        cout << ele << ' ';
        ele = 1000;
    }

    cout << endl;
}

int main() {

    int i = 0;
    int j[2] = {0, 1};

    print(i); 
    print(begin(j), end(j));
    print(j);

    print(begin(j), end(j));
    
    return 0;
}

