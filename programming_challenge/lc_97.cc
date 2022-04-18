#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto l1 = s1.length();
        auto l2 = s2.length();
        if (s1.length() == 0 && s3 == s2) {
            return true;
        }

        if (s2.length() == 0 && s3 == s1) {
            return true;
        }

        vector<vector<bool>> result = {l1, vector<bool>(l2, false)};

        result[0][0] = true;
        size_t t1 = 0, t2 = 0;

        queue<pair<int, int>> q;

        while (t1 + t2 >= s3.length() || q.empty()) {
            if (t1+1 <= s1.length()) {
                result[t1+1][t2] = (result[t1][t2] && (s1[t1] == s3[t1+t2]))
                if (result[t1+1][t2]) {
                    q.push(make_pair(t1+1, t2));
                }
            }
            if (t2+1 <= s2.length()) {
                result[t1][t2+1] = (result[t1][t2] && (s2[t2] == s3[t1+t2]))
                if (result[t1][t2+1]) {
                    q.push(make_pair(t1+1, t2));
                }
            }

        }


    }
};

int main() {
    Solution s;

    //cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    //cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc");
    //cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc");

    return 0;
}
