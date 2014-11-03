/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_28.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 17:15:20
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <string>
#include <forward_list>

using namespace std;

void func(forward_list<string> &lStr, string s1, string s2) {

    auto it = lStr.begin();
    auto prev = lStr.before_begin();

    while (it != lStr.end()) {
        if (*it == s1) {
            lStr.insert_after(it, s2);
            return;
        }
        ++it;
        prev++;
    }
    lStr.insert_after(prev, s2);
}

int main() {

    forward_list<string> l{"ab", "cd", "ef", "gh", "ij"};

    func(l, "ee", "hello");


    for(auto & str : l) {
        cout << str << endl;
    }
    
    return 0;
}
