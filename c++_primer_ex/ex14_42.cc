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
#include <iterator>

using namespace std;
using namespace std::placeholders;

int main() {

    int n;

    vector<int> v {10, 20, 30, 40, 50, 1024, 1025, 1026};
    vector<string> v2 {"pooh", "pooh", "find"};

    cout << count_if(v.begin(), v.end(), bind(greater<int>(), _1, 1024)) << endl;

    cout << *find_if(v2.begin(), v2.end(), bind(not_equal_to<string>(), _1, "pooh")) << endl;

    transform(v.begin(), v.end(), v.begin(), bind(multiplies<int>(), _1, 2));

    ostream_iterator<int> iter_cout(cout, " ");
    copy(v.begin(), v.end(), iter_cout);

    return 0;
}
