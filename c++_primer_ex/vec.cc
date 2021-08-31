/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: vec.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-23-2015 12:45:38
 * @version $Revision$
 *
 **************************************************************************/

#include <vector>
#include <array>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

void func(int* a) {

}

int main() {
    //vector<int> v;
    list<int> v;

    int a[5] = {1, 2, 3, 4, 5};

    auto it = v.begin();
    for (auto i : a) {
        it = v.insert(it, i);
        //v.push_front(i);
    }

    for (auto i : v) {
        cout << i  << endl;
    }

    array<int, 5> b {1, 2, 3, 4, 5};

    array<int, 5> c;

    c = b;

    cout << c[1] << endl;

    func(a);

    unordered_map<int, int> u;

    if (5 not in u) {
    }

    return 0;
}

