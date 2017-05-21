/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: random_str.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-21-2017 17:41:48
 * @version $Revision$
 *
 **************************************************************************/

#include <random>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int main() {
    ofstream f_out("1.txt", ios::out);
    string str, str2;
    mt19937 rd_gen((random_device())());

    for (auto i = 0; i < 10*10000; ++i) {
        str.append("abcdef", 6);
    }

    for (auto i = 0; i < 5*1000; ++i) {
        str2.append("abcdef", 6);
    }

    f_out << str << 'h' << endl;
    f_out << str2 << 'h' << endl;

    f_out.close();

    return 0;
}

