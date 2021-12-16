#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t i = 0;
        size_t j = 0;

        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                res.push_back(nums1[i++]);
            } else {
                res.push_back(nums2[j++]);
            }
        }

        if (i < nums1.size()) {
            res.insert(res.end(), nums1.begin()+i, nums1.end());
        }

        if (j < nums2.size()) {
            res.insert(res.end(), nums2.begin()+j, nums2.end());
        }

        // debug
        /*
        ostream_iterator<int> o_iter(cout, " ");
        copy(res.begin(), res.end(), o_iter);
        cout << endl;
        */
        if (res.size() == 0) return 1;

        auto mid = res.size() / 2;
        if (res.size() % 2 == 0) {
            return (static_cast<double>(res[mid]) + res[mid-1]) / 2.0;
        }

        return static_cast<double>(res[mid]);
    }
};

int main() {
    vector<int> nums1 {};
    vector<int> nums2 {};

    Solution s;

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
