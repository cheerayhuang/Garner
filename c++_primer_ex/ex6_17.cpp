/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_17.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 13:33:59
 * @version $Revision$
 *
 **************************************************************************/

#include <string> 
#include <iostream> 

using namespace std; 

bool JudgeUpper(const string& a) {
    for (auto it = a.begin(); it != a.end();  ++it) {
        if (isupper(*it)) 
            return true;
    }

    return false;
}

string& StrLower(string& b) {

    for (auto it = b.begin(); it != b.end(); ++it) {
        if (isupper(*it)) {
            *it = (*it-65) + 97; 
        }
    }

    return b; 
}

int main() {
    string a, b; 
    cin >> a >> b;

    if (JudgeUpper(a)) {
        cout << a << " has upper letter" << endl;
    } 

    cout << StrLower(b) << endl;

    return 0;
}


