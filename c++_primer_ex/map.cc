/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: map.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 18:08:05
 * @version $Revision$
 *
 **************************************************************************/
#include <iostream>
#include <map> 
#include <set>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {

    vector<pair<int, int>> v; 
    map<int ,int > m (v.begin() , v.end());
    set<int> s;
    find_if(m.begin(), m.end(), [](const pair<const int, int> ){ return true; });
    find(s.begin(), s.end(), 0);


    return 0;
}


