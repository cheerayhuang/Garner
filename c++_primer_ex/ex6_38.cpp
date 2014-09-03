/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_38.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-03-2014 10:21:37
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

int odd [] {1, 3, 5, 7, 9};
int even[] {0, 2, 4, 6, 8};

decltype(odd) & arrRef(int i) {
    return (i % 2) ? odd : even;
}

int main() {
    
    auto res = arrRef(5); 
    cout << res[0] << endl; 
    res = arrRef(4); 
    cout << res[0] << endl; 

    return 0;
}

