/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_37.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 10:26:51
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>
#include <list>
#include <algorithm> 
#include <iterator>

using namespace std; 

int main() {
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list <int> lst;

    copy(v.crbegin() + 2, v.crend()-3, inserter(lst, lst.end())); 

    for_each(lst.cbegin(), lst.cend(), [](const int &i) { cout << i << " "; });

    return 0;
}

