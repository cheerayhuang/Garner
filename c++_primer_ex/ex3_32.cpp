/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_32.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-12-2014 09:13:21
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

int main() {

    vector<int> ivec(10);
   
    for (auto beg = ivec.begin(); beg != ivec.end(); ++beg) {
        *beg = beg-ivec.begin();
    }

    vector<int> ivec2(ivec); 

    for (auto i : ivec2) {
        cout << i << endl; 
    } 

    return 0;
}

