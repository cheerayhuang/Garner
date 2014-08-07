/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_11.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-07-2014 14:58:18
 * @version $Revision$
 *
 **************************************************************************/

#include <string>
#include <iostream>

using namespace std;

int main() {
    const string str = "hello";
    // though c is "const reference", but in range_for, it can be still assigned by next char in str.
    for (auto &c : str) {
        decltype(c) cc = str[0];
        cout << c << endl;
    }

    return 0;
}


