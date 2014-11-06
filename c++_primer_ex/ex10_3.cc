/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_3.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 11:37:52
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <string>
#include <cstring>

using namespace std; 

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};

    cout << accumulate(v.begin(), v.end(), 0) << endl;

    vector<double> double_v{1.1, 2.2, 3.3, 4.4, 5.5};

    cout << accumulate(double_v.begin(), double_v.end(), 0.0f) << endl;

    cout << accumulate(double_v.begin(), double_v.end(), 0) << endl;

    vector<short> short_v{1, 2, 3, 4, 5, 6};
    
    //cout << (short_v == v) << endl;
    cout << equal(short_v.begin(), short_v.end(), v.begin()) << endl;

    vector<const char*> str_vec {"hello", "world"};
    char *s = new char[10];
    strcpy(s, "world");
    vector<const char*> str_vec2 {"hello", s};

    cout << (str_vec == str_vec2) << endl;
    cout << equal(str_vec.begin(), str_vec.end(), str_vec2.begin()) << endl;

    return 0;
}
