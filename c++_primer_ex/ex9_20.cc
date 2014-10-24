/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_20.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 11:42:09
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <vector>

using namespace std; 

int main() {
    list<int> list1 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    deque<int> deq;
    array<int, 10> arr;
    forward_list<int> flist1;
    vector<int> vec;


    for (auto & i : list1) {
        int itArr = 0;
        if (i % 2) {
            deq.insert(deq.begin(), i);
            arr[itArr++] = i;
        }
        else {
            flist1.insert_after(flist1.before_begin(), i);
            vec.push_back(i);
        }
    }
    return 0;
}


