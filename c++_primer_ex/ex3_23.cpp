/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_23.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-08-2014 11:23:09
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <vector>

using namespace std;

int main() {
    int n; 
    vector<int> ivec;

    for (int i = 0; i < 10; ++i) {
        if (!(cin >> n))  {
            break;
        }
        ivec.push_back(n);
    }

    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it *= 2;
    }

    for (auto it = ivec.cbegin(); it != ivec.cend(); ++it) {
        cout << *it << endl; 
    }

    return 0;
}
