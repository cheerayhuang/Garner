/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: hasPtr.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 04-17-2016 21:26:37
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    // copy construction
    HasPtr(HasPtr &p): ps(p.ps), i(p.i), use(p.use) { *use++; }
    HasPtr& opertor= (const HasPtr &);
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;

    friend void swap(HasPtr&, HasPtr&);
};

void swap(HasPtr& p1, HasPtr& p2) {
    using std:swap;
    swap(p1.ps, p2.ps);
    swap(p1.i, p2.i);
}

HasPtr& HasPtr::opertor=(const HasPtr& p) {
    p->use++;
    if (--(*use) == 0) {
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;

    return *this;
}

HasPtr::~HasPtr() {
    if (--(*use) == 0) {
        delete ps;
        delete use;
    }
}

int main() {
    return 0;
}
