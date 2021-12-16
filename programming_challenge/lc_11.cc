/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: lc_11.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-02-2021 11:29:49
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


class Solution {
public:

    int maxArea(vector<int>& height) {
        auto max_height = *max_element(height.begin(), height.end());
        size_t max_area = 0;

        while(max_height) {
            auto cmp_f = [max_height](int x) -> bool {
                return x >= max_height;
            };

            auto left_iter = find_if(height.begin(), height.end(), cmp_f);

            auto right_iter = find_if(height.rbegin(), height.rend(), cmp_f);

            auto width = std::distance(make_reverse_iterator(left_iter+1), right_iter);
            if (labs(max_height * width) > max_area) {
                max_area = labs(max_height * width);
            }

            max_height--;

        }

        return max_area;
    }
};

int main() {

    vector<int> nums{1,8,6,2,5,4,8,3,7};

    Solution s;

    cout << s.maxArea(nums) << endl;
    nums.assign({1, 1});
    cout << s.maxArea(nums) << endl;

    return 0;
}
