/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex6_21.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 13:17:33
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream> 
#include <iterator>

using namespace std; 

void print(int i) {
    cout << i << endl; 
}

void print(int (&i)[2]) {
    for(auto it = begin(i); it != end(i); ++it) {
        cout << *it << ' ';
    }

    cout << endl; 
}

void print(int* beg, int *end)
{
    while(beg != end) {
        cout << *beg << ' '; 
        ++beg;
    }
        
    cout << endl; 
}

int main() {

    int i = 0; 

    int j[2] = {0, 1}; 

    print(i); 
    print(begin(j), end(j));
    print(j);

    return 0;
}
