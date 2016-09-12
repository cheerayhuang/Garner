/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: template_const_ref.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-25-2016 11:36:16
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

template <typename T>
void func(const T& t) {
    cout << t << endl;
}

template <typename T>
void func(T&& t) {
    cout << "T&& " << t << endl;

}

/*void func(int &&& t) {
    cout << "int && " << t << endl;
}*/

int main() {
    const int i = 5;
    func(i);

    func(5);

    //int && ri = i;

    return 0;
}

