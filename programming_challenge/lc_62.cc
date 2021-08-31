#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> map;

        for (auto i = 0; i < 100; ++i) {
            //map.emplace_back(100);
            map.emplace_back(vector<int>(100, 0));
        }

        map[0][0] = 1;

        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (i-1 >= 0) {
                    map[i][j] += map[i-1][j];
                }

                if (j-1 >= 0) {
                    map[i][j] += map[i][j-1];
                }
            }
        }

        return map[m-1][n-1];

    }
};

int main() {
    Solution s;

    //cout << s.uniquePaths(3, 7) << endl;
    cout << s.uniquePaths(0, 0) << endl;

    return 0;
}
