/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: fact.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 14:10:51
 * @version $Revision$
 *
 **************************************************************************/

#include "Chapter6.h" 

int fact(int i) {
    int sum{1}; 

    while (i > 1) {
        sum *= i--; 
    }

    return sum;
}

