#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res{nums[0]};


        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] > res[res.size()-1]) {
                res.push_back(nums[i]);
            }

            if (auto it = upper_bound(res.begin(), res.end(), nums[i]); it != res.end())
                *it = nums[i];
        }

        return res.size();
    }
};

int main() {

    Solution s;

    vector<int> vec{10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(vec) << endl;

    return 0;
}
