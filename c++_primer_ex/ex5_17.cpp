/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex5_17.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-21-2014 09:13:26
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector> 

using namespace std; 


int main() {
    vector<int> ivec1, ivec2; 

    
    int n; 
    while(cin >> n && n != -1) {
        ivec1.push_back(n);
    }

    cout << "input 2nd vec: " << endl; 

    while(cin >> n && n != -1) {
        ivec2.push_back(n);
    }

    auto it1 = ivec1.begin(); 
    auto it2 = ivec2.begin(); 

    while (it1 != ivec1.end() && it2 != ivec2.end() && *it1 == *it2) {
        ++it1; 
        ++it2;
    }

    if (it1 == ivec1.end() || it2 == ivec2.end()) {
        cout << "true" << endl;
        return 0;
    }        

    cout << "false" << endl;
    return 0;
}


