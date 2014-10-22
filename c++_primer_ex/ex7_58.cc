/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex7_40.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-22-2014 15:56:15
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>

using namespace std; 

class A {
    public: 
        void func(int);
        static int param;
        static double rate; 
        static constexpr int vecSize = 20;

        static vector<double> vec;

};

int A::param = 10; 
double A::rate = 6.5;
vector<double> A::vec{vecSize};

//constexpr int A::vecSize;

//const int *p = &A::vecSize;

constexpr int i = A::vecSize;

void A::func(int=param) {
}


int main() {

    A a; 

    a.func(a.vecSize);

    i = 10;

    return 0;
}
