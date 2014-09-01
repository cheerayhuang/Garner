/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_25.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-01-2014 11:29:11
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cerr << "please inpute two strings." << endl;
        return -1;
    }
    string s1{argv[1]}; 
    string s2{argv[2]};

    cout << s1 + s2 << endl; 

    return 0;
}


