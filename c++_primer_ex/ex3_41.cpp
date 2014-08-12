/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_41.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-12-2014 10:27:57
 * @version $Revision$
 *
 **************************************************************************/


#include <iterator>
#include <vector> 
#include <iostream> 

using namespace std; 


int main() {
    
    int a[5] = {1, 2, 3, 4, 5};
    vector<int> ivec(begin(a)+1, end(a));


    for (auto i : ivec) {
        cout << i << endl; 
    }

    return 0;
}

