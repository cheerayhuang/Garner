/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex_switch.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-19-2014 10:01:36
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

int main() {

    switch(1) {
        case 1:
            ;
        default:
            ;    // shold have a statment here, though it is null.
    }

    switch(1) {
        case 1: 
            int i; 
            //int j = 1; // error: j is initialized here, but this scope maybe ignored by case statement. 
            break;
        case 2: 
            //int j = 2;
            break;
    }

    return 0;
}


