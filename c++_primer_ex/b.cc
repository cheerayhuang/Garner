/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: b.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-04-2016 16:52:37
 * @version $Revision$
 *
 **************************************************************************/


#include "a.h"


namespace sdkbox {

    void A::func(my_enum) { }
    //void A::func(A::my_enum_in_a) { }

    A::my_enum_in_a m;

};

int main () {

    sdkbox::A a;

    a.func(sdkbox::my_enum(sdkbox::red));
    a.func(sdkbox::A::my_enum_in_a(sdkbox::red));
    //a.func(A::my_enum(red));


    return 0;
}
