/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex7_4.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-21-2014 10:02:42
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 

class Person {

friend istream& Read(istream&, Person & p);
friend ostream& Write(ostream&, const Person &p);

private:
    string addr;
    string name {""};

public:
    Person() = default;
    ~Person() = default;

    Person(const Person&) = default;

    Person(const string &addr, const string &name) : name(name), addr(addr) {

    }

    Person(istream &is) {
        Read(is, *this);
    }
};

istream& Read(istream&, Person &p);
ostream& Write(ostream&, const Person &p);

istream& Read(istream& is, Person &p) {
    is >> p.name >> p.addr;

    return is;
}

ostream& Write(ostream& os, const Person &p) {
    os << "name: " << p.name << " addr: " << p.addr << endl;

    return os;
}

int main() {
    Person p("cd", "hqy");
    Write(cout, p);

    return 0;
}

