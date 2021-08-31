
#include <iostream>
#include <unordered_map>
#include <algorithm>


using namespace std;

class Solution {
public:
    void search(unordered_map<int, int> &set, const vector<int>& v, vector<vector<int>> &res, vector<int>& r) {

        if (r.size() == v.size()) {
            res.push_back(r);
            return ;
        }

        for (auto &&i : v) {
            if (set[i] > 0) {
                --set[i];
                r.push_back(i);
                search(set, v, res, r);
                ++set[i];
                r.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, int> candidates_set;

        for_each(nums.cbegin(), nums.cend(), [&candidates_set](int i) {
            candidates_set[i]++;
        });

        vector<vector<int>> res;
        vector<int> r;

        search(candidates_set, nums, res, r);

        return res;
    }
};


int main() {
    vector<int> n {1, 2, 3};

    Solution s;
    auto res = s.permute(n);

    for (auto && i : res) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}
