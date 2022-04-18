#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        auto row = triangle.size();
        if (row == 0) {
            return triangle[0][0];
        }

        vector<vector<int>> dp(row, vector<int>(row, std::numeric_limits<int>::max()));
        dp[0][0] = triangle[0][0];

        for (int r = 1; r < row; ++r)
            for (int c = 0; c <= r; ++c) {
                if (c-1 >=0 && c-1 < r) {
                    dp[r][c] = std::min(dp[r][c], dp[r-1][c-1]+triangle[r][c]);
                }

                if (c < r) {
                    dp[r][c] = std::min(dp[r][c], dp[r-1][c]+triangle[r][c]);
                }
            }

        auto min_res = std::numeric_limits<int>::max();
        for (auto j = 0; j < row; ++j) {
            if (dp[row-1][j] < min_res) min_res = dp[row-1][j];
        }

        return min_res;
    }

};

int main() {

    vector<vector<int>> v1 {
        {-5},
    };

    vector<vector<int>> v2 {
        {-2},
        {-5, -10},
        {10, 30, -5},
    };

    Solution s;
    cout << s.minimumTotal(v1) << endl;
    cout << s.minimumTotal(v2) << endl;


    return 0;
}
