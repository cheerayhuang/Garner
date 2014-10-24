/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_31.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 18:12:51
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <forward_list>
#include <list> 

using namespace std;

int main() {
    forward_list<int> flist {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto iter = flist.begin();
    auto prev = flist.before_begin();

    while (iter != flist.end()) {
        if (*iter % 2) {
            iter = flist.insert_after(prev, *iter);
            ++iter; 
            ++prev;
        } else {
            iter = flist.erase_after(prev);
            continue;
        }

        ++iter; 
        ++prev;
    }

    list<int> l {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iterList = l.begin();

    while (iterList != l.end()) {
        if (*iterList % 2) {
            iterList = l.insert(iterList, *iterList);
            ++iterList;
        } else {
            iterList = l.erase(iterList);
            --iterList;
        }
        ++iterList;
    }

    for (auto & i : flist) {
        cout << i << " ";
    }
    cout << endl;

    for (auto & i : l) {
        cout << i << " ";
    }
    cout << endl;

    flist.emplace_front(10);
    flist.push_front(10);
    flist.pop_front();

    return 0;
}
