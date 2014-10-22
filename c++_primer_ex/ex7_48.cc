/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex7_48.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-22-2014 12:15:31
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Sales {
    public:
        Sales() = default;
        Sales(const string & str) { cout << "sales(string)" << endl; }

        //Sales &combine(Sales) { cout << "combine(Sales)" << endl;}
        //Sales &combine(Sales&) {cout << "combine(Sales&)" << endl; }
        Sales &combine(const Sales&) const {cout << "combine(const Sales&)" << endl;}
};

int main() {
    
    string nullStr("hello");
    Sales item1(nullStr);
    Sales item2("hello");

    item1.combine(nullStr);
    item2.combine("hello");

    return 0;
}

