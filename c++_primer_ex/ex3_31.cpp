/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_31.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-12-2014 09:10:12
 * @version $Revision$
 *
 **************************************************************************/

#include <cstddef> 
#include <iostream> 

using namespace std; 

int main() {
    int arr[10]; 

    for (size_t i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    int arrCopy[10];

    for (size_t i = 0; i < 10; ++i) {
        arrCopy[i] = arr[i];
        cout << arrCopy[i] << endl; 
    }

    return 0;
}

