/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex12_26.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 21:50:56
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

int main() {
    allocator<string> alloc;

    auto const p = alloc.allocate(20);

    string s;

    auto q = p;

    while (cin >> s) alloc.construct(q++, s);

    for (auto beg = p; beg < q; beg++) {
        cout << *beg << endl;
    }

    while(q != p)
        alloc.destroy(--q);

    alloc.deallocate(p, 20);

    return 0;
}

