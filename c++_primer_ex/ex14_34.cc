/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: ex14_34.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-08-2016 21:01:00
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;

class If_then_else {
    public:
        int operator() (int a, int b, int c) {
            return  a ? b : c;
        }
};

int main() {

    If_then_else if_;

    cout << if_(5, 6, 7) << endl;


    return 0;
}

