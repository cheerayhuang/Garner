/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: test_reverse_iter.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-04-2016 11:26:25
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

#include <vector>

using namespace std;



int main() {

    vector<int> vec = {1, 2, 3, 4, 5};

    for (vector<int>::reverse_iterator iter = static_cast<vector<int>::reverse_iterator>(vec.end()-1); iter != vec.rend(); ++iter)
        cout << *iter << ' ';
    cout << endl;

    cout << vec.rbegin() - vec.rend() << endl;
    cout << vec.cbegin() - vec.end() << endl;

    cout << distance(vec.begin(), vec.end()) << endl;
    auto it = vec.begin();
    advance(it, 5);

    if (it == vec.end()) cout << "at the end!" << endl;

    auto rit = vec.rbegin();
    advance(rit, 5);

    if (rit == vec.rend()) cout << "at the rend!" << endl;

    return 0;
}


