/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex12_16.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 14:27:40
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

void func(int *p) {
    cout << "hello world" << endl;
    delete p;
}

void test_func(int) { }

void func2(decltype(test_func)*) {
    cout << "hello beijing" << endl;
}

int main() {

    unique_ptr<int, decltype(func)*> p(new int(1024), func);


    func2(test_func);

    return 0;
}
