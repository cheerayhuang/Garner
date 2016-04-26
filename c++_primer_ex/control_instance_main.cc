/**************************************************************************
 *
 * Copyright (c) 2013 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: control_instance_main.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 04-26-2016 15:19:48
 * @version $Revision$
 *
 **************************************************************************/

// important! template codes must be included,
// though you only use "extern template".
#include "control_instance.h"

extern int ex_int_var;
extern template class A<int>;

int main() {
    class A<int> a;

    a.print();

    return 0;
}


