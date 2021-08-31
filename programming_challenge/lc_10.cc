#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> res{p.size(), vector<bool>(s.size())};

        if (p == ".*") return true;

        if (s[0] == p[0] || p[0] == '.') {
            res[0][0] = true;
        } else {
            return false;
        }

        if (p[1] == '.') {
            res[1][0] = true;
        }

        if


        for (auto i = 1; i < p.size(); ++i) {
            for (auto j = 1; j < s.size(); ++j) {
                if (p[i] == s[j] || p[i] == '.') {
                    res[i][j] |= res[i-1][j-1];
                }

                if (p[i] == '*' && (s[j] == p[i-1] || p[i-1] == '.')) {
                    res[i][j] |= true;;
                }

                if (p[i] != '*' && j > i) break;
            }
        }

        return res[p.size()-1][s.size()-1];
    }
};



int main() {
    return 0;
}
