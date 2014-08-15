/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex4_21.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-15-2014 15:27:42
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector> 

using namespace std; 

int main() {

    vector<int> ivec {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it = (*it % 2 == 0) ? *it : *it*2;
        cout << *it << endl;
    }

    return 0;
}



