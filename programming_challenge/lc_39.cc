#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;


class Solution {
public:
    void search(unordered_map<int, int> &set, const vector<int>& v, int t, int min, vector<vector<int>> &res, vector<int>& r) {

        if (t == 0) {
            res.push_back(r);
            return ;
        }

        for (auto &&i : v) {
            if (i >= min && set[i] > 0 && ((t-i != 0 && t-i >= min) || t-i == 0)){
                --set[i];
                r.push_back(i);
                auto ori_min = min;
                if (i > min) {
                    min = i;
                }
                search(set, v, t-i, min, res, r);
                min = ori_min;
                ++set[i];
                r.pop_back();
            }
        }
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, int> candidates_set;
        auto min = numeric_limits<int>::max();

        for_each(candidates.cbegin(), candidates.cend(), [&candidates_set, &min, target](int i) {
            candidates_set[i] = target / i;
            if (i < min)  min = i;
        });

        vector<vector<int>> res;
        vector<int> r;
        search(candidates_set, candidates, target, min, res, r);

        return res;
    }
};

int main() {
    Solution s;

    vector<int> v {2, 3, 6, 7};
    vector<int> v2 {2, 3, 5};
    vector<int> v3 {1};

    //auto res = s.combinationSum(v, 7);
    auto res = s.combinationSum(v3, 2);

    for (auto && i : res) {
        for (auto &&j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
