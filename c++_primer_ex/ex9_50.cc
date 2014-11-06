/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_50.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 10:51:31
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    vector<string> v {"1", "a1", "345", "6", "fas77a", "8", "9"};
    vector<int> res;

    for (auto &s : v) {
        res.push_back(stoi(s.substr(s.find_first_of("123456789", 0))));
    }

    cout << count(res.begin(), res.end(), 1) << endl;
    cout << accumulate(res.begin(), res.end(), 0) << endl;

//    cout << stoi("a77") << endl; 
    size_t p;
    cout << stoi("77a756", &p) << endl;
    cout << stoi(string("77a757").substr(string("77a757").find_first_of("123456789", p))) << endl;

    return 0;
}
