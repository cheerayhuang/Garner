#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto sum = numeric_limits<int>::min();
        auto max_sum = numeric_limits<int>::min();

        for (auto &&i : nums) {
            if (sum == numeric_limits<int>::min() || sum + i < i) {
                sum = i;
            } else {
                sum += i;
            }

            if (sum > max_sum) {
                max_sum = sum;
            }
        }

        return max_sum;
    }
};

int main() {
    vector<int> v1{-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v2{-2};

    Solution s;

    cout << s.maxSubArray(v2) << endl;

    return 0;
}
