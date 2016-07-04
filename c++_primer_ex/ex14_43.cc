/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex14_43.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-04-2016 22:33:56
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

int main() {

    int n;
    cin >> n;

    vector<int> v {10, 20, 30, 40, 50};

    auto fn = bind(modulus<int>(), _1, n);

    auto t = any_of(v.begin(), v.end(), [fn](int i)->bool { if (fn(i) != 0) return true; return false;});

    cout <<  !t << endl;

    return 0;
}
