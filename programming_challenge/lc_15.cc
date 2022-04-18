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
#include <deque>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        deque<int> d {nums.begin(), nums.end()};

        unordered_map<int, int> is_not_used;
        for(auto &&i : nums) {
            is_not_used[i]++;
        }

        auto it = d.begin();
        auto other_it = d.end();
        auto switc_it = [&d, &it, &other_it]() -> decltype(d.begin()) {
            if (it == d.begin()) it = d.end();
            else it = d.begin();

            return it;
        };

        while(0) {
            if (abs(*it) < abs(*(other_it-1))) {
                switc_it();
                continue;
            }

            if (abs(*it) > abs(*(other_it-1)) + abs(*(other_it-2))) {
                d.erase(it);
                switc_it();
                continue;
            }

            is_not_used[*it]--;
            is_not_used[*(other_it-1)]--;

            if (is_not_used[*it + *other_it] > 0) {
                is_not_used[*it + *other_it]--;
            }




        }


        return vector<vector<int>> {vector<int> {}};
    }
};

int main() {
    vector<int> nums {-1,0,1,2,-1,-4};

    Solution s;

    s.threeSum(nums);

    return 0;
}

