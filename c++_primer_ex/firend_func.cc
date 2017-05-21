/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: firend_func.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-07-2017 15:55:26
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

struct Base {
    friend void func() {}
};

void func2() { func(); }

int main() {


    return 0;
}
