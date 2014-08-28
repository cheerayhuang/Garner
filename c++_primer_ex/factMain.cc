/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: factMain.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 14:12:03
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

#include "Chapter6.h"

using namespace std;

int main() {

    int n = 0;
    cout << "inpute n: " << endl; 
    cin >> n; 

    cout << fact(n) << endl; 

    return 0;
}

