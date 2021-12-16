/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: lc_15.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-03-2021 15:37:34
 * @version $Revision$
 *
 **************************************************************************/

#include <iterator>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        positive_nums =


        return vector<vector<int>> {vector<int> {}};
    }
};

int main() {
    vector<int> nums {-1,0,1,2,-1,-4};

    Solution s;

    s.threeSum(nums);

    return 0;
}

