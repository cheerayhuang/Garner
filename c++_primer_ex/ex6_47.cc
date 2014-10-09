/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_47.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-09-2014 17:25:18
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std;

void func(vector<int> v) {
    if (v.empty()) {
        return ;
    }
#ifndef NDEBUG
    cout << "size= " << v.size() << endl;
#endif
    cout << *(v.begin()) << endl;

    func(vector<int>(v.begin()+1, v.end()));
}

int main() {
    vector<int> vec{1,2,3,4,5};

    func(vec);
    return 0;
}

