/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_10.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-07-2014 14:42:08
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>
#include <cctype>

using namespace std;


int main() {
    string str; 
    cin >> str;

    for (auto c : str) {
        if (!ispunct(c))  {
            cout << c; 
        }
    }

    cout << endl; 
    return 0;
}


