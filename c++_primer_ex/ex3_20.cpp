/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_20.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-08-2014 10:59:24
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 


int main() {
    
    vector<int> ivec; 
    int n;

    while(cin >> n) {
        ivec.push_back(n);
    }

    for(decltype(ivec.size()) i = 0; i < ivec.size()-1; ++i) {
        cout << ivec[i]+ivec[i+1] << ' ';    
    }

    cout << endl;
    cout << ivec[0] + ivec[ivec.size()-1] << endl;

    return 0;
}


