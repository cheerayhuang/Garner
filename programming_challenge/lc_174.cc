#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        auto row = dungeon.size();
        if (row == 0) {
            return 1;
        }

        auto col = dungeon[0].size();
        auto res = std::max(1-dungeon[row-1][col-1], 1);

        vector<vector<int>> dp(row, vector<int>(col, std::numeric_limits<int>::max()));

        for (int r = row-1; r >=0; --r)
            for (int c = col-1; c >=0; --c) {
                if (c == col-1 && r == row-1) {
                    dp[r][c] = res;
                    continue;
                }

                if (c == col-1) {
                    dp[r][c] = std::max(dp[r+1][c] - dungeon[r][c], 1);
                    continue;
                }

                if (r == row-1) {
                    dp[r][c] = std::max(dp[r][c+1] - dungeon[r][c], 1);
                    continue;
                }

                dp[r][c] = std::min(std::max(dp[r+1][c]-dungeon[r][c], 1), std::max(dp[r][c+1]-dungeon[r][c], 1));
            }

        return dp[0][0];
    }

};

int main() {

    vector<vector<int>> v1 {
        {-5},
    };

    vector<vector<int>> v2 {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5},
    };

    Solution s;
    cout << s.calculateMinimumHP(v1) << endl;
    cout << s.calculateMinimumHP(v2) << endl;


    return 0;
}
