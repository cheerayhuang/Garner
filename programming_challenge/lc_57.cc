#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> res;

        for (auto iter = intervals.cbegin(); iter != intervals.cend(); ++iter) {
            if (newInterval[0] >= (*iter)[0]) {

            }


            res.push_back(*iter);
        }

    }
};

int main() {
    return 0;
}
