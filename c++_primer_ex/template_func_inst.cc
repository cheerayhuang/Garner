/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: template_func_inst.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 12-17-2016 21:41:14
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

template <typename T> void func(const T& val) {
    std::cout << "hello world" << std::endl;
}

template void func(const double&);

