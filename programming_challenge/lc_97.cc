#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        //string::iterator cur_s1_iter = s1.begin();
        //string::iterator cur_s2_iter = s2.begin();
        //
        auto cur_s1_pos = -1;
        auto cur_s2_pos = -1;

        for (auto beg = s3.begin(); beg != s3.end(); ++beg) {

            auto p1 = s1.find(*beg, cur_s1_pos+1);
            if (p1 != string::npos) {
                cur_s1_pos = p1;
                continue;
            }

            auto p2 = s2.find(*beg, cur_s2_pos+1);
            if (p2 != string::npos) {
                cur_s2_pos = p2;
                continue;
            }

            return false;
        }

        return true;
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
