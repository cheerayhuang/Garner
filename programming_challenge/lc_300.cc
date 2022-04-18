#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res{nums[0]};


        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] > res.back()) {
                res.push_back(nums[i]);
                continue;
            }

            auto u = std::upper_bound(res.begin(), res.end(), nums[i], [](int x, int y) {return x <= y;});
            *u = nums[i];
        }

        /*ostream_iterator<int> cout_iter(cout, " ");
        std::copy(res.begin(), res.end(), cout_iter);
        */
        return res.size();
    }
};

int main() {

    Solution s;

    vector<int> vec{10,9,2,5,3,7,101,18};
    cout << s.lengthOfLIS(vec) << endl;

    vector<int> vec2{7, 7, 7, 7, 7, 7, 7};
    cout << s.lengthOfLIS(vec2) << endl;

    return 0;
}
