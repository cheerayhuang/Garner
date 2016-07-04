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

    //HasPtr & operator=(const HasPtr&);
    HasPtr & operator=(HasPtr);

    ~HasPtr() { delete ps; }

//private:
public:
    string *ps;
    int i;

private:

friend void swap(HasPtr&, HasPtr&);
};

HasPtr::HasPtr(const HasPtr& h) {
    auto s = *(h.ps);
    //delete ps;

    i = h.i;
    ps = new string(s);

    cout << "copy construct" << endl;
}

/*HasPtr& HasPtr::operator=(const HasPtr& h) {
    auto s = *(h.ps);
    delete ps;

    i = h.i;
    ps = new string(s);

    cout << "copy operator =" << endl;

    return *this;
}*/

HasPtr& HasPtr::operator=(HasPtr h) {
    swap(*this, h);
    return *this;
}

void swap(HasPtr &h1, HasPtr &h2) {

    using std::swap;

    swap(h1.ps, h2.ps);
    swap(h1.i, h2.i);

    cout << "swap" << endl;
}


int main() {
    HasPtr h1("hello");
    HasPtr h2 = h1;
    HasPtr h3(h1);

    cout << *(h2.ps) << endl;
    cout << *(h3.ps) << endl;

    HasPtr h4;

    h2.i = 1024;

    h4 = h2;
    cout << *(h4.ps) << endl;
    cout << h4.i << endl;

    h2.i = 0;
    swap(h4, h2);

    cout << h4.i << endl;

    return 0;
}

