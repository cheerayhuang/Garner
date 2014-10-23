/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex8_1.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-23-2014 11:47:27
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string> 

using namespace std; 

istream& func(istream& is) {
    string str, buf;

    while (is >> buf) {
       str = str + buf; 
    }

    cout << str << endl;
    
    is.clear();
}

int main() {

    func(cin);
    return 0;
}

