/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: demo_define.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-07-2016 21:53:04
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

        using my_type2 = int;
class A {
    public:
        using my_type = int;
        my_type a;

        void func() {
            my_type2 a;
        }

};

        //using my_type2 = int;
int main() {

    return 0;
}

