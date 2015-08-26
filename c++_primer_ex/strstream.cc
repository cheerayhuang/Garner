/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: strstream.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-23-2015 12:55:55
 * @version $Revision$
 *
 **************************************************************************/

#include <sstream>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    istringstream strIn {"abc k def"};

    string str, str2;
    int i;

    cout << strIn.str() << endl;
    strIn >> str >> str >> str2;

    cout << str << str << str2<< endl;

    cout << strIn.str() << endl;

    istringstream strIn2 {"a b c 10 d"};
    strIn.clear();
    istream_iterator<string> in(strIn), eof;

    if (in == eof) {
        cout << "create stream iterator failed." << endl;
    }
    while(in != eof) {
        cout << *in << endl;
        ++in;
    }


    str = "a,b,c";

    auto r = find(str.crbegin(), str.crend(), ',');
    cout << *r << endl;
    cout << *r.base() << endl;
    cout << string(r.base(), str.cend()) << endl;

    int it = 0;
    istringstream in_stream{"1 2 3 4"};
    while ( it++ < 10) {
        istream_iterator<int> in(in_stream), eof;

        while(in != eof) {
            cout << *in++ << ' ';
        }
    }

    return 0;
}

