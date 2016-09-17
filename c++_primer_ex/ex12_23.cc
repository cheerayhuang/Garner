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
#include <algorithm>

using namespace std;


unique_ptr<char[]> func(const string& s1, const string& s2);

unique_ptr<char[]> func(const char* c1, const char* c2) {

    return func(string(c1), string(c2));
}

unique_ptr<char[]> func(const string& s1, const string& s2) {
    unique_ptr<char[]> u(new char[s1.size()+s2.size()]);

    for (auto i = 0; i < s1.size(); ++i) {
        u[i] = s1[i];
    }

    auto j = 0;
    for (auto i = s1.size(); i < s1.size()+s2.size(); ++i, ++j) {
        u[i] = s2[j];
    }

    return u;
}

pair<char*, char*> func2(const string& s1, const string& s2) {
    allocator<char> a;

    auto beg = a.allocate(s1.size()+s2.size());
    auto end = uninitialized_copy(s1.begin(), s1.end(), beg);
    end = uninitialized_copy(s2.begin(), s2.end(), end);

    return make_pair(beg, end);
}

int main() {

    auto u = func("hello", "world");

    for (auto c=0; c < 10; ++c) {
        cout << u[c];
    }
    cout << endl;

    auto p = func2("world ", "hello!");
    for(auto iter = p.first; iter != p.second; ++iter) {
        cout << *iter;
    }
    cout << endl;

    return 0;
}
