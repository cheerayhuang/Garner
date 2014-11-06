/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_43.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 09:29:00
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std;

string func(string name, const string& prefix, const string& suffix) {
    name.insert(name.begin(), prefix.begin(), prefix.end()); 
    name.append(suffix.begin(), suffix.end());

    return name;
}

string func2(string name, const string &prefix, const string &suffix) {
    name.insert(0, prefix);
    name.append(suffix.c_str(), suffix.size());

    return name;
}

int main() {
    string str("thothruthuthothru");

    string::size_type beg = 0;
    while (beg < str.size()) {
        auto pos = str.find("thru", beg);
        if (pos != string::npos) {
            str.erase(pos, 4);
            str.insert(pos, "through");
            beg = pos + 1;
        }
        else {
            break;
        }
    }

    beg = 0; 
    while (beg < str.size()) {
        auto pos = str.find("tho", beg);

        if (pos != string::npos) {
            str.replace(pos, 3, "though");
            beg = pos+1;
        }
        else {
            break;
        }
    }

    cout << str << endl;

    cout << func("huang" , "Mr.", "Dr.") << endl;
    cout << func2("huang", "Mrs.", "II") << endl;

    return 0;
}

