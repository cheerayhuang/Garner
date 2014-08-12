/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_42.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-12-2014 10:31:41
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector> 

using namespace std;

int main() {

    vector<int> ivec(10, 5);
    int a[10];

    for(auto beg = ivec.begin(); beg != ivec.end(); ++beg) {
       a[beg-ivec.begin()] = *beg; 
    }


    for(auto i : a) {
        cout << i << endl; 
    }
    
    return 0;
}

