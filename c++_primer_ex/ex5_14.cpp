/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex5_14.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-19-2014 10:48:55
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int main() {
    string  str{""};
    vector<string> istr;

    while (cin >> str) {
        istr.push_back(str);
    }

    unsigned cnt{1}; 
    unsigned maxCnt{cnt};
    string maxStr{""};

    if (istr.empty()) {
        cout << 0 << endl; 
        return 0;
    }

    for (auto it = istr.begin()+1; it != istr.end(); ++it) {
        if (*it == *(it-1)) {
            ++cnt;
        }
        else if (cnt > maxCnt) {
            maxCnt = cnt; 
            cnt = 1; 
            maxStr = *(it-1);
        }
    }

    cout << maxCnt << endl; 
    cout << maxStr << endl; 

    return 0;
}

