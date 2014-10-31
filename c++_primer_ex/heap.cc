/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: heap.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-31-2014 15:49:07
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

void MakeHeap(vector<int> &v) {
    for (vector<int>::size_type i = 1; i < v.size(); ++i) {
        int father = (i % 2) ? ((i-1)/2) : ((i-2)/2);

        auto j = i;
        while(father >= 0 && v[j] > v[father]) {
            auto tmp = v[j]; 
            v[j] = v[father];
            v[father] = tmp;

            j = father; 
            father = (j % 2) ? ((j-1)/2) : (j/2-1);
        }
    }
}

int main() {
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    MakeHeap(v);

    for (auto &i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

