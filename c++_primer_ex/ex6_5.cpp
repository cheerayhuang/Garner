/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_5.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 14:08:04
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

int Abs(int i) {
    return (i < 0) ? -i : i;
}

int main() {
    cout << Abs(-5) << endl;
    cout << Abs(5) << endl; 

    return 0;
}


