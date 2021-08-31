#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res(nums.size(), 1);


        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = 0; j < i; ++j) {

                if (nums[j] < nums[i] && res[j]+1 > res[i]) {
                    res[i] = res[j]+1;
                }
            }
        }

        sort(res.begin(), res.end());

        return res[nums.size()-1];
    }
};

int main() {

    Solution s;

    vector<int> vec{10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(vec) << endl;

    return 0;
}
