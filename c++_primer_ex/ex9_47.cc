/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_47.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 10:36:05
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 

int main() {

    string str("ab2c3d7R4E6");

    string::size_type beg = 0;

    while (beg < str.size()) {
        auto pos = str.find_first_of("123456789", beg);     
        if (pos != string::npos) {
            cout << str[pos];
            beg = pos+1;
        }
        else {
            break;
        }
    }
    cout << endl;

    beg = 0;
    while (beg < str.size()) {
        auto pos = str.find_first_not_of("123456789", beg);
        if (pos != string::npos) {
            cout << str[pos];
            beg = pos+1;
        }
        else {
            break;
        }
    }
    cout << endl;


    str.find_first_of('c', 1);

    auto pos_iter = str.find("huang");
    cout << pos_iter << endl;

    return 0;
}

