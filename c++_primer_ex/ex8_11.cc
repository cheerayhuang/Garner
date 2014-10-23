/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex8_11.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-23-2014 15:02:13
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

struct A {
    string a, b, c;

    A(initializer_list<string> il) { cout << "hei, hei do nothing" << endl;}
    //A(string, string) { cout << "A(string, string)" << endl; }
    A() = default;
};

int main() {
    string line, word;
    vector<PersonInfo> people;

    istringstream record;

    while (getline(cin, line)) {
        PersonInfo info;

        record.str(line);
        record >> info.name;

        while (record >> word) {
            info.phones.push_back(word);
        }

        people.push_back(info);
        record.clear();
    }

    for (const auto &i : people) {
        ostringstream oss;
        
        oss << i.name << " :";
        for (const auto &j : i.phones) {
            oss << " " << j;
        }
        cout << oss.str() << endl;
    }

    A a {"a"};

    cout << a.a << a.b << a.c << " end" << endl;

    return 0;
}
