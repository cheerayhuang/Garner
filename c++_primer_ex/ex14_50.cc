/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex14_50.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-05-2016 00:07:46
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

struct LongDouble {
    LongDouble(double = 0.0) {};
    operator double();
    operator float() {};
    operator short() {};

};

void Calc(int) { cout << "int" << endl; }
void Calc(LongDouble) { cout << "LongDouble" << endl; }

int main() {

    LongDouble l;

    int i = l;
    float j = l;


    double k;
    Calc(k);


    return 0;
}
