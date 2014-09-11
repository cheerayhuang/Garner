/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_42.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-11-2014 10:07:05
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

string make_plural(size_t ctr, const string & word, const string &ending = "s") {
    return (ctr > 1) ? word+ending : word;
}

int main() {

    cout << make_plural(2, "failure") << endl; 
    cout << make_plural(2, "success", "es") << endl; 

    return 0;
}

