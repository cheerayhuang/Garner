/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_22.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 13:09:59
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 


void Exchange(int * &p1, int * &p2) {
    int *p = p1; 
    p1 = p2; 
    p2 = p;
}

int main() {

    int i = 1, j = 2; 
    int *pi = &i , *pj = &j;

    Exchange(pi, pj);

    cout << *pi << endl; 
    cout << *pj << endl; 

    return 0;
}

