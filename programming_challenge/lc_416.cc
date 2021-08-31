#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        //auto sum = accumulate(nums.begin(), nums.end(), 0);
        auto sum = 0;
        auto max = 0;
        auto min = numeric_limits<int>::max();

        for_each(nums.begin(), nums.end(), [&](auto&& x) {
            if (x > max) {
                max = x;
            }

            if (x < min) {
                min = x;
            }

            sum += x;
        });

        if (sum % 2 != 0) return false;
        if (max > sum/2) return false;

        vector<unordered_map<int, bool>> res;

        for (auto i = 0; i <= nums.size(); ++i) {
            res.emplace_back(unordered_map<int, bool>{});
            res[i][0] = true;
        }


        auto sum2 = 0;
        for (auto i = 1; i <= nums.size(); ++i) {
            sum2 += nums[i-1];
            auto j_end = sum2;
            if (sum2 > sum/2) j_end = sum/2;
            for (auto j = min; j <= j_end; ++j) {

                if (j - nums[i-1] >= 0) res[i][j] |= res[i-1][j-nums[i-1]];
                res[i][j] |= res[i-1][j];

                if (res[i][sum/2]) return true;
            }
        }

        return res[nums.size()][sum/2];
    }
};

int main() {
    Solution s;

    vector<int> vec{1, 5, 11, 5};
    vector<int> vec2{1, 2, 3, 5};
    vector<int> vec3{2, 2, 3, 5};
    cout << s.canPartition(vec) << endl;
    cout << s.canPartition(vec2) << endl;
    cout << s.canPartition(vec3) << endl;

    return 0;
}
