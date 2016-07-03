/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex12_10.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 14:12:42
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

void process(shared_ptr<int> ptr) {

    cout << ptr.use_count() << endl;
}

int main() {
    shared_ptr<int> p(new int(1024));

    process(shared_ptr<int>(p));

    cout << p.use_count() << endl;

    process(p);

    return 0;
}

