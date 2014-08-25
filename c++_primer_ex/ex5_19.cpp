/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex5_19.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-25-2014 09:12:56
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

int main() {

    do {
        string str1{""}, str2{""}; 
        
        cout << "inpute two strings:" << endl;
        cin >> str1 >> str2; 
        cout << (str1.length() < str2.length() ? str1 : str2) << endl;
    }while (cin);

    return 0;
} 

