/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_18.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 11:31:08
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <deque> 
#include <list>
#include <string>

using namespace std; 

int main() {

    string str;
    deque<string> deq;
    list<string> listStr;

    while (cin >> str) {
        deq.push_back(str);
        listStr.push_back(str);
    }

    for (auto & s : deq) {
        cout << s << endl;
    }

    for (auto &s : listStr) {
        cout << s << endl;
    }
    return 0;
}

