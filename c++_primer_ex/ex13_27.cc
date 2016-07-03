/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex13_27.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-04-2016 00:04:08
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class HasPtr {

public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0), use(new size_t(1)) {}

    HasPtr(const HasPtr& h);

    HasPtr & operator=(const HasPtr&);

    ~HasPtr();

//private:
public:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::HasPtr(const HasPtr& h) {

    i = h.i;
    ps = h.ps;
    use = h.use;
    ++*use;

    cout << "copy construct" << endl;
}

HasPtr& HasPtr::operator=(const HasPtr& h) {

    ++*h.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }

    i = h.i;
    ps = h.ps;
    use = h.use;

    cout << "copy operator =" << endl;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
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

    cout << hex << h2.ps << endl;
    cout << hex << h4.ps << endl;

    return 0;
}



