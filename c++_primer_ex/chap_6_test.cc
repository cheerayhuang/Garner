/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: chap_6_test.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-13-2015 00:38:30
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int func(int i) {
    return i;
}

typedef int (*func_type)(int);

auto get_func() -> func_type {
    return func;
}

int func_multi_args(vector<int> v) {

    for (const auto &i : v) {
        cout << i << endl;
        decltype(i) k = 10;
    }
}

int main() {
    auto f = get_func();
    cout << f(10) << endl;

    func_multi_args({1, 2, 3, 4, 5});

    return 0;
}
