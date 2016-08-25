/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_ptr_reset.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-25-2016 12:49:01
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

template<typename C, typename... T>
shared_ptr<C> make_shared2(T&&... args) {
    return shared_ptr<C>(new C(std::forward<T>(args)...));
}

int main() {

    shared_ptr<int> p = make_shared2<int>(5);

    cout << p.use_count() << endl;

    shared_ptr<int> p1 = p;

    cout << p.use_count() << endl;

    p.reset();

    cout << p1.use_count() << endl;

    weak_ptr<int> w = p1;

    cout << p1.use_count() << endl;

    *p1 = 6;

    cout << * p1 << endl;

    unique_ptr<int> u(new int(*p1));

    *u = 7;

    cout << * u << endl;

    cout << w.use_count() << endl;

    return 0;
}
