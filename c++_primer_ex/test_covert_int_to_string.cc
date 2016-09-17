/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_covert_int_to_string.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-14-2016 19:01:49
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;




int main() {

    vector<uint8_t> vec{1, 2, 3, 4, 5, 0};

    string  str;


    for(auto i : vec) {
        //cout << static_cast<unsigned int>(i) << endl;
        str.append(1,static_cast<char>(i));
    }

    for(auto i : str) {
        cout << static_cast<int>(i) << endl;
    }


    return 0;
}


