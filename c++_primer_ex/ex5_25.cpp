/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex5_25.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-28-2014 10:56:26
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <stdexcept> 

using namespace std; 

int main() {
    int i, j;

    while(true) {
        try {
            cin >> i >> j; 
            if (j == 0) {
                throw exception();
                //throw runtime_error("div 0 err!");
            }
            cout << i / j << endl; 
            break;
        } catch (exception &e) { 
            cout << e.what() << endl; 
            cout << "need to inpute again?" << endl; 
            char ch; 
            cin >> ch; 
            if (!cin || ch == 'n' || ch == 'N') {
                break;
            }
        }
    }

    return 0;
}

