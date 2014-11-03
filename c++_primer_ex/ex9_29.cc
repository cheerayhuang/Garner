/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_29.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 17:53:14
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

int main() {
    vector<int> vec(25);

    //vec.resize(100);
    vec.resize(10);

    cout << vec[90] << endl;
    //cout << vec.at(90) << endl;

    vector<int> vec2(1);
}

