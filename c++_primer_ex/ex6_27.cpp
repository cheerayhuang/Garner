/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_27.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-01-2014 12:14:09
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

void func(vector<int> l) {
//void func(initializer_list<int> l) {
    
    int sum = 0;
    for (auto &i : l) {
       sum += i;  
    }

    cout << sum << endl;
}

int main() {

    func({1, 2, 3});

    func({1,2,3,4,5});
    return 0;
}

