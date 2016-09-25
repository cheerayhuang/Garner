/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: template.cpp
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-25-2016 16:27:18
 * @version $Revision$
 *
 **************************************************************************/

#include "template.h"

template<typename T>
T my_max(T t1, T t2) {
    return (t1 > t2) ? t1 : t2;
}

template int my_max(int, int);
template double my_max(double, double);
