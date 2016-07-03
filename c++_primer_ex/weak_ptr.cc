/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: weak_ptr.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 14:52:44
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <memory>

using namespace std;

int main() {
    weak_ptr<int> w;

    shared_ptr<int> p = make_shared<int>(42);

    w = p;

    cout << p.use_count() << endl;

    auto p2 = w.lock();

    cout << p.use_count() << endl;

    return 0;
}

