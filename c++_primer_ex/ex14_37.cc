/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: ex14_37.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 03-10-2016 18:34:50
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class Equal {
    public:
        bool operator()(int a) {
            return (a == base);
        }

    private:
        int base{5};
    public:
        int j;
};

int main() {
    vector<int> v {1, 2, 3, 5, 5, 5};

    replace_if(v.begin(), v.end(), Equal(), 1024);

    ostream_iterator<int> out(cout);

    copy(v.begin(), v.end(), out);

    return 0;
}
