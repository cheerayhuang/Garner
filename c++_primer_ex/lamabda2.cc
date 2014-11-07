/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: lamabda2.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 10:00:50
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

int main() {
    size_t v1 = 42;

    auto f = [&v1]()->int { if (1+1==3) {return 0;} return ++v1; };
    v1 = 0;

    cout << f() << endl;

    return 0;
}

