/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_4.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-23-2014 16:32:03
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector> 

using namespace std;

auto Find(vector<int> vec, vector<int>::iterator beg, vector<int>::iterator end, int ele) -> decltype(end) {

    auto b = beg;

    while (b != end) {
        if (*b == ele) {
            break;
        }
        ++b;
    }
    
    return b;
}

int main() {
    vector<int> vec {1, 2, 3, 4, 5};

    auto it = Find(vec, vec.begin()+1, vec.end(), 5);
    if (it == vec.end()) {
        cout << "none" << endl;
    } else {
        cout << *it << endl;
    }

    return 0;
}

