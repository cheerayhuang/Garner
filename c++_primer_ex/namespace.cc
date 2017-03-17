/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: namespace.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 03-10-2017 23:35:06
 * @version $Revision$
 *
 **************************************************************************/

#include "namespace.h"

namespace test {
    void func() {
        cout << "hello func" << endl;
    }

    extern int k = 1023;

}

int main() {
    test::func();
    test::func2();

    cout << test::k << endl;

    return 0;
}
