/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex12_24.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 15:24:13
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <initializer_list>
#include <iterator>
#include <memory>

using namespace std;

int main() {
    //unique_ptr<initializer_list<char>> u(new initializer_list<char>{'a', 'b'});

    istream_iterator<char> in(cin), in_end;

    unique_ptr<char []> u(new char[10]);

    auto total = 0;
    auto len = 10;
    while (in != in_end) {
       u[total++] = *in++;
       if (total == len) {
           unique_ptr<char []> w(new char[total*2]);

           for (auto i = 0; i < total; ++i) {
               w[i] = u[i];
           }
           u.reset(w.release());
           len = total*2;
       }
    }

    for (auto i = 0; i < total; ++i) cout << u[i];

    cout << endl;

    return 0;
}

