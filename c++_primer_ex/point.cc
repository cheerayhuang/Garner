/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: point.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 03-16-2017 13:30:48
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

int main() {
    int i = 10;
    int *p = &i;

    uintptr_t v = reinterpret_cast<uintptr_t>(p);

    cout << p << endl;
    cout << v << endl;

    cout << sizeof v << endl;
    cout << sizeof(long) << endl;

    return 0;
}
