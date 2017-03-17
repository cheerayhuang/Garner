/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: shared_ptr.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 03-05-2017 01:47:41
 * @version $Revision$
 *
 **************************************************************************/


#include <memory>
#include <iostream>

using namespace std;

void func(const shared_ptr<int> &r) {
    weak_ptr<int> p = r;

    cout << *(p.lock().get()) << endl;
}

int main() {

    shared_ptr<int> p = make_shared<int>(5);

    cout << p.use_count() << endl;

    func(p);

    cout << p.unique() << endl;

    return 0;
}
