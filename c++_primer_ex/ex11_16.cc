/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex11_16.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 14:49:07
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <map>
#include <set>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {

    map<int, int> m;



    m.insert({11, 8});
    auto it = m.begin();
    // because it->first is a const
    //*it = pair<int, int> (5, 6);


    for(auto & i : m) {
        cout << i.first << endl;
        cout << i.second << endl;
    }

    multiset<string> c; 
    vector<string> v;

    copy(v.begin(), v.end(), inserter(c, c.end()));
    //copy(v.begin(), v.end(), back_inserter(c));
    copy(c.begin(), c.end(), inserter(v, v.end()));
    copy(c.begin(), c.end(), back_inserter(v));

    ++m.at(11);

    cout << m[11] << endl;
    m[1] = 10;
    m[2] = 12;
    m[5] = 13;

    cout << m.equal_range(1).first -> first << "==>" << m.equal_range(1).first->second << endl;
    cout << m.equal_range(4).first -> first << endl;
    cout << m.equal_range(4).second -> first << endl;
    cout << m.lower_bound(6)->first << "==>" << m.lower_bound(6)->second << endl;
    cout << m.upper_bound(6)->first << "==>" << m.upper_bound(6)->second << endl;

    //cout << m[6] << endl;

    if (m.find(6) == m.end()) {
        cout << "not exist"  << endl;
    }

    return 0;
}
