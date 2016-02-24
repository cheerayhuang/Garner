/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: stof.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 12-07-2015 16:56:30
 * @version $Revision$
 *
 **************************************************************************/
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


int main() {

    string str = "0.7";
    istringstream ss(str);

    float f = stof(str);

    cout << f << endl;

    float f2;
    ss >> f2;

    cout << f2 << endl;


    return 0;
}



