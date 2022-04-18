#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        auto row = grid.size();
        if (row == 0) {
            return 0;
        }

        auto col = grid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, std::numeric_limits<int>::max()));
        dp[0][0] = grid[0][0];

        for (int r = 0; r < row; ++r)
            for (int c = 0; c < col; ++c) {
                if (r == 0 && c == 0) {
                    continue;
                }

                if (r-1 >= 0) {
                    dp[r][c] = std::min(dp[r][c], dp[r-1][c]+grid[r][c]);
                }

                if (c-1 >= 0) {
                    dp[r][c] = std::min(dp[r][c], dp[r][c-1]+grid[r][c]);
                }
            }

        return dp[row-1][col-1];
    }

};

int main() {

    vector<vector<int>> v1 {
        {-5},
    };

    vector<vector<int>> v2 {
        {1, 3, 1},
        {5, 10, 1},
        {10, 30, 1},
    };

    Solution s;
    cout << s.minPathSum(v1) << endl;
    cout << s.minPathSum(v2) << endl;


    return 0;
}
