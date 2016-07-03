/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex12_6.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 10:20:14
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> * AllocVect() {
    return new vector<int>;
}

void GetInput(vector<int> *p) {
    istream_iterator<int> in_iter(cin), in_end;

    while(in_iter != in_end) {
        p->push_back(*in_iter++);
    }
}

void Output(vector<int> *p) {
    for(auto i : *p) {
        cout << i << endl;
    }
}

int main() {

    auto p = AllocVect();

    GetInput(p);

    Output(p);

    delete p;

    return 0;
}
