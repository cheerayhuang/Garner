/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: kmp2.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-21-2017 14:26:56
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int func(const string& str1, const string& str2) {
    vector<int> v(str1.length());

    v[0] = -1;
    for (auto i = 1; i < str1.length(); ++i) {
        auto j = i-1;
        v[i] = -1;
        while (j != -1 && str1[i] != str1[v[j]+1]) j = v[j];
        if (j != -1) v[i] = v[j]+1;
    }

    auto j = 0;
    for (auto i = 0; i < str2.length();) {
//        cout << i << ' ' << j << endl;
        if (str2[i] != str1[j]) {
            if (j == 0) {
                i++;
                continue;
            }
            j = v[j-1]+1;
        } else {
            j++;
            if (j == str1.length()) return i-str1.length()+1;
            i++;
        }
    }

    return -1;
}


int main() {

    cout << func("abc", "abcdefg") << endl;
    cout << func("a", "abcdefg") << endl;
    cout << func("g", "abcdefg") << endl;
    cout << func("abc", "abababababababc") << endl;
    cout << func("ababcbc", "abababababababcbc") << endl;

    string s1, s2;
    ifstream f_in("1.txt");
    f_in >> s2 >> s1;
    f_in.close();

    struct timespec t1, t2;
    clock_gettime(CLOCK_MONOTONIC, &t1);
    cout << func(s1, s2) << endl;
    clock_gettime(CLOCK_MONOTONIC, &t2);
    cout << "spend time: " << (t2.tv_sec-t1.tv_sec) + (t2.tv_nsec-t1.tv_nsec) / 1e9 << endl;

    return 0;
}
