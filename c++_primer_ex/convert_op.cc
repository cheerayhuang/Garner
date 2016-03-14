/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: convert_op.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-11-2016 19:03:28
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>

using namespace std;


class A {

public:
    //operator int&() { static int k = 5;  return k; }

    A(double = 0.0) { }
    operator double() {return 0.2;}
    operator float() { return 0.1;}

};

void calc(int) { cout << "int" << endl; }
void calc(A) { cout << "A" << endl; }


int main() {

    A a;

    //auto &k = static_cast<int&>(a);

    //cout << k << endl;

    //int ex1 = a;
    float ex2 = a;

    double d = 0.5;
    calc(d);


    return 0;
}


