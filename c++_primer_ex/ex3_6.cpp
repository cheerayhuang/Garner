/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_6.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-07-2014 14:31:38
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {

    string str; 

    cin >> str; 

    for (auto &c : str) {
       c = 'X'; 
    }

    cout << str << endl;
    
    return 0;
}


