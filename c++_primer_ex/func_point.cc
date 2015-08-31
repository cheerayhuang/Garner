/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: func_point.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-09-2014 17:00:51
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

typedef int func(int *, int);

func* f1(int);

template <class T1, class T2>
void foo() {

    cout << "T1, T2" << endl;

}

template <class T1>
void foo() {
    cout << "T1, int" << endl;
}

constexpr int returnI(int j) {
    return j;
}

using func_point_type = void (int);


func_point_type * return_a_func() {
    return [](int) {};
}

int main() {

    foo<int>();
    foo<int, int>();

    const int j = 5;
    constexpr int i = returnI(j);

    int k = 10;
    //constexpr int ii = returnI(k);
    //


    return 0;
}

