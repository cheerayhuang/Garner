#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    istream_iterator<int> ci(cin);
    istream_iterator<int> e;
    ostream_iterator<int> co(cout, " ");

    //vector<tuple<int, int, int> > res;

    int i, j;
    int max_step = 0;
    while (cin) {
    //while (ci != e) {

        i = *ci++;
        j = *ci++;

        auto is_swap = false;
        if (i > j) {
            swap(i, j);
            is_swap = true;
        }

        max_step = 0;
        for (auto beg = i; beg <= j; ++beg) {
            auto cur_num = beg;
            auto step = 1;
            while (cur_num != 1) {
                if (cur_num % 2 == 0) {
                    cur_num /= 2;
                } else {
                    cur_num = 3*cur_num + 1;
                }
                ++step;
            }

            if (step > max_step) {
                max_step = step;
            }
        }

        //res.push_back(make_tuple(i, j, max_step));
        if (is_swap) {
            //cout << j << " " << i << " ";
            *co++ = j;
            *co++ = i;
        } else {
            *co++ = i;
            *co++ = j;
            //cout << i << " " << j << " ";
        }

        cout << max_step << "\n";
    }

    /*
    for (auto beg = res.begin(); beg != res.end(); ++beg) {
        cout << std::get<0>(*beg) << " " << std::get<1>(*beg) << " " << std::get<2>(*beg);
        if (beg != res.end()-1) {
            cout << "\n";
        }
    }*/


    vector<char> arr(1000000000, 10);
    return 0;
}
