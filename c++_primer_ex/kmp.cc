/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: kmp.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-31-2016 17:22:21
 * @version $Revision$
 *
 **************************************************************************/


#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

string::size_type Kmp(const string &str, const string &substr) {
    auto len_substr = substr.size();
    vector<int> next(substr.size());
    fill(next.begin(), next.end(), -1);

    for (int i = 1; i < substr.size(); ++i) {
        auto j = i-1;
        do {
            j = next[j];
        } while (j != -1 && substr[i] != substr[j+1]);
        if (j != -1) next[i] = j+1;
        else if (substr[i] == substr[0]) next[i] = 0;
    }

    auto j = 0;
    for (int i = 0; i < str.size(); ++i, ++j) {

        if (str[i] != substr[j]) {
            if (j == 0) {
                j = -1;
                continue;
            }
            --i;
            j = next[j-1];
            continue;
        }

        if (j == substr.size()-1) return i-substr.size()+1;
    }

    return string::npos;
}

int main() {

    string s1 = "abababc" , s2 = "ababc";
    auto r = Kmp(s1, s2);
    if (r != string::npos) {
        cout << s1 << endl;
        cout << setw(r+1) << '^' << endl;
    }
    else cout << "Not found!" << endl;

    return 0;
}

