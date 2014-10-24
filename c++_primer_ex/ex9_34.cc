/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex9_34.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-24-2014 18:06:58
 * @version $Revision$
 *
 **************************************************************************/
#include <iostream> 
#include <vector>

using namespace std;

int main() {
    
    vector<int> vi{1, 2, 3, 4};

    auto iter = vi.begin();
    while (iter != vi.end()) {
        if (*iter % 2) {
            iter = vi.insert(iter, *iter);
            ++iter; 
        }
        ++iter;
    }

    for (auto & i : vi) {
        cout << i << endl;
    }

    return 0;
}


