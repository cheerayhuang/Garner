/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_1.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 11:25:22
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std; 

int main() {
    vector<int> v; 

    int i;

    while(cin >> i) {
        v.push_back(i);
    }

    cout << count(v.begin(), v.end(), 5) << endl;

    return 0;
}
