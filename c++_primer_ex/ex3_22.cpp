/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_22.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-08-2014 11:09:01
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <vector> 
#include <cctype>

using namespace std; 


int main() {
    string str; 
    vector<string> svec; 

    while(getline(cin, str)) {
        svec.push_back(str);
    }

    for (auto it = svec.begin(); it != svec.end() && !it->empty(); ++it) {
        for (auto its = it->begin();  its != it->end(); ++its) {
            if (isalpha(*its)) {
                *its = toupper(*its);
            }
        }

        cout << *it << endl; 
    }
    return 0;
}


