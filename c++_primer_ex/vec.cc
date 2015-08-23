/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: vec.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-23-2015 12:45:38
 * @version $Revision$
 *
 **************************************************************************/

#include <vector>
#include <iostream>
#include <list>

using namespace std;

int main() {
    //vector<int> v;
    list<int> v;

    int a[5] = {1, 2, 3, 4, 5};

    auto it = v.begin();
    for (auto i : a) {
        //it = v.insert(it, i);
        v.push_front(i);
    }

    for (auto i : v) {
        cout << i  << endl;
    }

    return 0;
}

