/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: lc_1458.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-13-2021 16:11:33
 * @version $Revision$
 *
 **************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> res;
        for (auto i = 0; i <= nums1.size(); ++i)
            res.emplace_back(vector<int>(nums2.size()+1, 0));

        for (auto i = 1; i <= nums1.size(); ++i)
            for (auto j = 1;  j <= nums2.size(); ++j) {
                auto max = res[i-1][j-1] + nums1[i-1]*nums2[j-1];
                if (i-1 > 0 && res[i-1][j] > max) max = res[i-1][j];
                if (j-1 > 0 && res[i][j-1] > max) max = res[i][j-1];
                if (j-1 > 0 && i-1 >0 && res[i-1][j-1] > max) max = res[i-1][j-1];
                if (nums1[i-1] * nums2[j-1] > max) max = nums1[i-1]*nums2[j-1];

                res[i][j] = max;
            }

        return res[nums1.size()][nums2.size()];
    }
};

int main() {
    vector<int> vec1{2, 1, -2, 5};
    vector<int> vec2{3, 0, -6};

    vector<int> vec3{3, -2};
    vector<int> vec4{2, -6, 7};


    vector<int> vec5{-1, -1};
    vector<int> vec6{1, 1};

    /*
     * [-3,-8,3,-10,1,3,9]
[9,2,3,7,-9,1,-8,5,-1,-1]
*/
    vector<int> vec7{-3,-8,3,-10,1,3,9};
    vector<int> vec8{9,2,3,7,-9,1,-8,5,-1,-1};


    Solution s;

    cout << s.maxDotProduct(vec1, vec2) << endl;
    cout << s.maxDotProduct(vec3, vec4) << endl;
    cout << s.maxDotProduct(vec5, vec6) << endl;
    cout << s.maxDotProduct(vec7, vec8) << endl;

    return 0;
}


