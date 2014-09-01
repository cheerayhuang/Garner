/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_26.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-01-2014 11:41:29
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <iterator>

using namespace std; 

int main(int argc, char *argv[]) {

    for (auto it = 0; it != argc; ++it) {
        cout << argv[it] << endl;
    }
    return 0;
}

