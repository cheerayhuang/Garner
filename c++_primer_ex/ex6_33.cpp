/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_33.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-03-2014 10:12:09
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

void func(const vector<int> & ivec) {

    if (ivec.size() != 0) {
        cout << *ivec.begin() << endl;
        //func(vector<int>(ivec.begin()+1, ivec.end()));
        func(vector<int>{ivec.begin()+1, ivec.end()});
    }
}

int main() {
   
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7};

    func(ivec); 
    
    return 0;
}

