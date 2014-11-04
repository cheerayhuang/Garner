/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_41.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 09:25:45
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string> 
#include <vector>

using namespace std; 

int main() {

    vector<char> vch {'a', 'e', 'i', 'o', 'u'};

    string str(vch.begin(), vch.end()); 

    cout << str << endl;

    return 0;
}

