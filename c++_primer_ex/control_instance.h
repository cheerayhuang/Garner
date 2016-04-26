/**************************************************************************
 *
 * Copyright (c) 2013 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: 1.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 04-26-2016 15:17:03
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

template<typename T>
class A {
    T i;
    T *pi;
    const T &ri;

public:
    void print() {
        std::cout << i << " " << *pi << " " << ri << std::endl;
    }

    // show correct initializing reference position:
    //wrong: A(){ ri = i; }
    A():ri(i) {}

};
