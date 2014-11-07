/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_34.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 09:53:20
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5};

    for_each(v.crbegin(), v.crend(), [](const int &i) { cout << i << " "; });

    return 0;
}
