/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex13_5.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-03-2016 22:11:24
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class HasPtr {

public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) {}

    HasPtr(const HasPtr& h);

    HasPtr & operator=(const HasPtr&);

    ~HasPtr() { delete ps; }

//private:
public:
    string *ps;
    int i;
};

HasPtr::HasPtr(const HasPtr& h) {
    auto s = *(h.ps);
    delete h.ps;

    i = h.i;
    ps = new string(s);

    cout << "copy construct" << endl;
}

HasPtr& HasPtr::operator=(const HasPtr& h) {
    auto s = *(h.ps);
    delete h.ps;

    i = h.i;
    ps = new string(s);

    cout << "copy operator =" << endl;
}


int main() {
    HasPtr h1("hello");
    HasPtr h2 = h1;
    HasPtr h3(h1);

    cout << *(h2.ps) << endl;
    cout << *(h3.ps) << endl;

    HasPtr h4;

    h4 = h2;
    cout << *(h4.ps) << endl;

    return 0;
}

