/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: ex14_35.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-08-2016 22:06:56
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>

using namespace std;

class InputString {

    public:
        string operator()() {
            string s;
            while(getline(in, s))
            {
                lines.push_back(s);
            }

            if (!in.eof()) {
                cout << "input error" << endl;
            }

            return string();
        }

        InputString(istream& i) : in(i), lines() {}

    private:
        istream &in;

    public:
        vector<string> lines;
};

int main() {

    InputString i(cin);

    i();

    for (auto line : i.lines) {
        cout << line << endl;
    }

    return 0;
}
