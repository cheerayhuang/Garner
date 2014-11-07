/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_36.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 10:03:31
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <list> 
#include <algorithm>

using namespace std; 

int main() {
    list<int> lst {1, 2, 3, 0, 4, 5, 6};
    vector<int> v (lst.begin(), lst.end());

    auto p = find(lst.crbegin(), lst.crend(), 0);
    cout << *p << endl;

    auto p1 = find(v.crbegin(), v.crend(), 0);
    cout << v.crend() - p1 << endl;
    cout << *p1 << endl; 

    return 0;
}

