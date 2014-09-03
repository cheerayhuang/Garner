/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_37.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-03-2014 10:24:47
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 

string str[10] {"abc", "def", "ghi", "jkl", "mn"};

string (&func1()) [10] {
    return str; 
}

using STR_REF = string (&) [10];
typedef string (&STR_REF2) [10];

STR_REF2 func2(){ 
    return str;
}

auto func3() -> string(&)[10] {
    return str;
}

decltype(str) & func4() {
    return str;
}

int main() {

    cout << func1()[0] << endl; 
    cout << func2()[1] << endl;

    cout << func3()[2] << endl;
    cout << func4()[3] << endl; 

    return 0;
}

