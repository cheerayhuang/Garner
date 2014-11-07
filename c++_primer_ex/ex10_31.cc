/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_30.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 10:54:33
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    istream_iterator<int> is_iter = cin, eof;
    ostream_iterator<int> os_iter(cout, " ");

    vector<int>v (is_iter, eof);
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), os_iter);
    //*os_iter++ = static_cast<int>('\n');
    cout << endl;
    unique_copy(v.begin(), v.end(), os_iter);
    //os_iter = '\n';
    cout << endl;

    return 0;
}

