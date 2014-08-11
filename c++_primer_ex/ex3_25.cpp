/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_25.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-11-2014 09:10:09
 * @version $Revision$
 *
 **************************************************************************/

#include <vector> 
#include <iostream>

using namespace std;

int main() {

    vector<int> statics(11, 0);

    int n;

    while(cin >> n) {
        if (n <= 100 && n >= 0) {
            auto pos = statics.begin() + n/10;
            ++*pos;
        }
    }

    for (auto beg = statics.begin(); beg != statics.end(); ++beg) {
        cout << *beg << ' '; 
    }
    cout << endl;

    return 0;
}


