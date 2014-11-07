/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_33.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 11:20:14
 * @version $Revision$
 *
 **************************************************************************/

#include <fstream>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;
using namespace placeholders;

auto func(const int& i, int odd_or_even = 0) ->bool {
    if (i%2 != odd_or_even) {
        return true;
    }
    return false;
}

int main() {
    ifstream fin("ex10_33.txt");
    ofstream fout_odd("ex10_33_odd.txt");
    ofstream fout_even("ex10_33_even.txt");

    istream_iterator<int> is_iter(fin), eof;
    ostream_iterator<int> os_iter_odd(fout_odd, " ");
    ostream_iterator<int> os_iter_even(fout_even, "\n");

    vector<int> v(is_iter, eof);

    copy_if(is_iter, eof, os_iter_even, [](const int &i) { if (!(i % 1)) return true; return false; });
    copy_if(is_iter, eof, os_iter_odd, [](const int &i) { if (i % 2) { return true; } return false; });
    while(is_iter != eof) {
        cout << *is_iter << endl;
        ++is_iter;
    }

    /*copy_if(v.begin(), v.end(), os_iter_odd, bind(func, _1, 0));
    copy_if(v.begin(), v.end(), os_iter_even, bind(func, _1, 1));*/

    /*copy_if(is_iter, eof, os_iter_odd, bind(func, _1, 0));
    copy_if(is_iter, eof, os_iter_even, bind(func, _1, 1));*/

    fin.close();
    fout_odd.close();
    fout_even.close();
    
    return 0;
}

