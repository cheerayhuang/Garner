/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex10_6.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-04-2014 12:41:41
 * @version $Revision$
 *
 **************************************************************************/
#include <algorithm> 
#include <iostream> 

using namespace std;

void print(int a[]) {
    for (auto i = 0; i < 5; ++i) {
        cout << a[i] << " ";
    }

    cout << endl;
}

int main() {
    int a1[] = {1, 2, 3 ,4, 5};
    int a2[5]; 

    copy(a1, a1+5, a2);
    print(a2); 
    fill(a2, a2+5 , 0);

    copy(begin(a1), end(a1), begin(a2));
    print(a2);
    fill_n(a2, 5, 0);

    copy(begin(a1), a1+5, a2);
    print(a2);

    return 0;
}

