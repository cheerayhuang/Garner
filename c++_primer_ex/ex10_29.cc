/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_29.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 10:34:49
 * @version $Revision$
 *
 **************************************************************************/

#include <fstream> 
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("ex10_29.txt"); 

    istream_iterator<string> str_siter(fin), eof;
    vector<string> v;

    while(str_siter != eof) {
        v.push_back(*str_siter);
        str_siter++;
    }

    for_each(v.cbegin(), v.cend(), [](string s) { cout << s << " "; }); 

    cout << endl;

    ostream_iterator<string> str_soter(cout, " ");
    for_each(v.cbegin(), v.cend(), [=](string s) mutable { str_soter = s; }); 

    str_soter =  "\n";

    return 0;
}


