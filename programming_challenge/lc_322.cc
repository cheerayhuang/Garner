#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0) {
            return 0;
        }

        int min = numeric_limits<int>::max();
        //vector<int> res(amount+1, -1);

        unordered_map<int, int> res;

        for_each(coins.begin(), coins.end(), [&](auto &&i) {
            if (i < min) {
                min = i;
            }

            res[i] = 1;
        });


        if (res[amount] == 1) {
            return 1;
        }


        if (coins.size() == 1) {
            return amount % coins[0] == 0 ? amount/coins[0] : -1;
        }

        for (auto i = min; i <= amount; ++i) {
            if (i - min < min) continue;

            for (auto &&j : coins) {
                if (i-j > 0 && res[i-j] != 0 && (res[i-j]+1 < res[i] || res[i] == 0)) {
                    res[i] = res[i-j]+1;
                }
            }
        }

        return res[amount] > 0 ? res[amount] : -1;
    }
};

int main() {
    Solution s;

    //vector<int> vec{1, 2, 5};
    vector<int> vec{ 1, 2};
    cout << s.coinChange(vec, 2147483647) << endl;

    return 0;
}
