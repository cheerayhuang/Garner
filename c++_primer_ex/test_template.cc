/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_template.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-23-2016 21:59:00
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include "template.h"

using namespace std;

template<typename T, template<typename TT> class cont>
class C {

};

//extern template double my_max(double, double);

int main() {


    my_max(5.0, 6.0);

    return 0;
}

