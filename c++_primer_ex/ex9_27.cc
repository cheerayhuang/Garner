/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_27.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 17:00:40
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <forward_list>

using namespace std;

int main() {
    forward_list <int> flist {1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto prev = flist.before_begin();
    auto it = flist.begin();

    while (it != flist.end()) {
        if (*it % 2 ) {
            it = flist.erase_after(prev);
        }
        else {
            prev = it;
            it++;
        }
    }

    for (auto & i : flist) {
        cout << i << endl;
    }

    return 0;
}
