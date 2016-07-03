/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex12_23.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 14:59:58
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <memory>
#include <string>
#include <cstring>

using namespace std;

unique_ptr<char[]> func(const char* c1, const char* c2) {

    auto s1 = new char[15];
    strcpy(s1, c1);

    auto s2 = new char[15];
    strcpy(s2, c2);

    strcat(s1, s2);

    unique_ptr<char[]> u(new char[strlen(s1)]);
    for (auto i = 0; i < strlen(s1); ++i) {
        u[i] = s1[i];
    }

    return u;
}

int main() {

    auto u = func("hello", "world");

    for (auto c=0; c < 10; ++c) {
        cout << u[c];
    }

    cout << endl;

    return 0;
}
