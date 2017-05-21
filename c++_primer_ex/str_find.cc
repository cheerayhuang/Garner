/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: str_find.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-21-2017 17:34:53
 * @version $Revision$
 *
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int func(const string& s1, const string& s2) {

    for (auto i = 0; i < s2.length(); ++i) {

        auto k = i;
        auto j = 0;
        for (; j < s1.length(); ++j, ++k) {
            if (s1[j] != s2[k]) break;
        }

        if (j == s1.length()) return i;
    }

    return -1;
}

int main() {
/*
    cout << func("a", "abc") << endl;
    cout << func("c", "abc") << endl;
    cout << func("bc", "abbbbbbc") << endl;
    cout << func("abc", "abababababababc") << endl;
    cout << func("ababcbc", "abababababababcbc") << endl;
*/
    string s1, s2;
    ifstream f_in("1.txt");
    f_in >> s2 >> s1;
    f_in.close();

    cout << s2.length() << endl;
    cout << s1.length() << endl;

    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    cout << func(s1, s2) << endl;
    clock_gettime(CLOCK_MONOTONIC, &t2);
    cout << "spend time: " << (t2.tv_sec-t1.tv_sec) + (t2.tv_nsec-t1.tv_nsec) / 1e9 << endl;

    return 0;
}

