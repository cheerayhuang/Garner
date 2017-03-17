/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: auto.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 02-26-2017 10:09:03
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> *v = new vector<int>(5, 1);
    auto v2 = new vector<int>{5,1};

    auto p = new auto(5);
    auto p2 = new auto{5};

    return 0;
}
