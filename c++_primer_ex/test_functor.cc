/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_functor.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-25-2016 14:44:54
 * @version $Revision$
 *
 **************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5,5,5};

    cout << count(v.begin(), v.end(), 5) << endl;
    cout << count_if(v.begin(), v.end(), bind(equal_to<int>(), placeholders::_1, 5)) << endl;

    return 0;
}


