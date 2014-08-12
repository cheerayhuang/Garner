/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex3_43.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-12-2014 11:02:22
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 

using namespace std; 

int main() {

    int ia[3][4]; 

    cout << "version 1" << endl;
    for (decltype(ia[0]) i : ia)
        for (int j : i) 
        cout << j << endl ;
    
    cout << "version 2" << endl; 
    for (int i = 0; i < 3; ++i) 
        for(int j = 0; j < 4; ++j) 
            cout << ia[i][j] << endl;
    
    cout << "version 3" << endl;
    for (decltype(&ia[0]) i = ia; i < ia + 3; ++i) 
        for (auto j = *i; j < *i + 4; ++j) 
            cout << *j << endl; 

    return 0;
}

