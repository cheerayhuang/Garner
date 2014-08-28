/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_12.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 13:44:23
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

void Exchange(int &i , int &j) {
    int tmp = i; 
    i = j; 
    j = tmp; 
}

void Exchange(int *i , int *j) {
    int tmp = *i; 
    *i = *j; 
    *j = tmp;
}

int main() {

    int i = 1, j {2};

    Exchange(i, j);
    cout << i << ' ' << j << endl;
    Exchange(&i, &j);
    cout << i << ' ' << j << endl;
    return 0;
}

