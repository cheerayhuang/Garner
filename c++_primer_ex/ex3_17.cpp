/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_17.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-08-2014 10:39:07
 * @version $Revision$
 *
 **************************************************************************/

#include <string> 
#include <vector>
#include <iostream> 

using namespace std;

int main() {

    string str;
    vector<string> svec;

    while(cin >> str) {
        svec.push_back(str);
    }

    for(decltype(svec.size()) ix = 0; ix < svec.size(); ++ix) {
        string str = svec[ix]; 
        for (decltype(str.size()) si = 0; si < str.size(); ++si) {
            str[si] = toupper(str[si]);
        }
        cout << str << endl; 
    }

    return 0;
}

