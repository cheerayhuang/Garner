#include <iostream>

using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if (n == 1) {
            return maxSum;
        }

        if (maxSum == n) {
            return 1;
        }

        auto step = 2;
        /*
        if (index == 0 || index == n-1) {
            --step;
        }*/

        auto rest = maxSum - n;

        auto m = 0;
        auto s = 0;
        for (auto i = 1; s <= rest; i += step, ++m) {
            if (step == 0) {
                m += (rest-s) / i + 1;
                break;
            }
            s += i;
            if (m == index) {
                if (step > 0) --step;
            }

            if (m == n - index-1) {
                if (step > 0) --step;
            }
            //cout << s << endl;
        }

        return m;
    }
};

int main() {

    Solution s;

    cout << s.maxValue(9, 4, 764086444) << endl;
    cout << s.maxValue(3, 2, 18) << endl;
    cout << s.maxValue(6, 1, 10) << endl;
    cout << s.maxValue(4, 2, 6) << endl;
    return 0;
}
