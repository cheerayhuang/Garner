#include <iostream>
#include <vector>

using namespace std;

int count(const vector<int> &v) {

    if (v.size() == 0) {
        return 1;
    }

    auto res = 0;
    auto tmp_num = 0;
    for (auto i = 0; i < 2; ++i) {
        if (i == v.size()) break;

        tmp_num += tmp_num*10 + v[i];

        if (tmp_num > 0 && tmp_num <= 16) {
            auto tmp_v = vector<int>{v.begin()+i+1, v.end()};
            res += count(tmp_v);
        } else {
            break;
        }
    }

    return res;
}


int main() {

    vector<int> v{1, 1, 1, 3};
    cout << count(v) << endl;

    v.assign({1,1,5,3});
    cout << count(v) << endl;


    v.assign({1, 0, 1, 0, 1, 2, 1, 3, 1});
    cout << count(v) << endl;


    return 0;
}
