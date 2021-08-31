#include <iostream>
#include <bitset>
#include <limits>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        bitset<32> bit_left(left);
        bitset<32> bit_right(right);

        for (auto i = 0; i < bit_left.size(); ++i) {
            if (!bit_left[i]) {
                continue;
            }

            if (!bit_right[i]) {
                bit_left.reset(i);
                continue;
            }

            string str1(i, '1');
            string str2(32-i, '0');

            bitset<32> bit_tmp(str2+str1);
            auto bit_gen_num = bit_right | bit_tmp;
            bit_gen_num.reset(i);
            if (bit_gen_num.to_ulong() >= left) {
                bit_left.reset(i);
            }
        }

        return bit_left.to_ulong();
    }
};

int main() {
    Solution s;

    cout << s.rangeBitwiseAnd(5,7) << endl;
    cout << s.rangeBitwiseAnd(1,numeric_limits<int>::max()) << endl;
    cout << s.rangeBitwiseAnd(600000000, 2147483645) << endl;

    return 0;
}
