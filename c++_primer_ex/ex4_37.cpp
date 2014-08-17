/**************************************************************************
 *
 * Copyright (c) 2013 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex4_37.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@nibirutech.com
 * @date: 08-17-2014 13:53:48
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string> 

using namespace std; 

int main() {
    
    int i; 
    double d; 
    const string *ps; 

    char *pc {new char}; 
    void *pv; 

    pv = static_cast<void*>(const_cast<string*>(ps));
    i = static_cast<int>(*pc); 
    //i = *pc;

    pv = static_cast<void*>(&d); 

    pc = static_cast<char*>(pv);

    return 0;
}


