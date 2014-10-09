/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_44.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-09-2014 17:36:26
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <string>

using namespace std; 

constexpr
int func() { return 5; }

const int i = func();

//inline
constexpr
int IsShorter(int j) {
    return j*i;
}

int main() {
    
    cout << IsShorter(5) << endl; 
    const int j = 3;
    constexpr int k = IsShorter(j);

    return 0;
}
