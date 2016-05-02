/**************************************************************************
 *
 * Copyright (c) 2013 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: playing_with_wheels.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-01-2016 08:05:13
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>
#include <iterator>
#include <algorithm>
#include <queue>

using namespace std;

class Wheels {
public:
    Wheels() {
        start_ = InputWheel();
        target_ = InputWheel();
        forbidden_.insert(start_);
        bfs_.push({start_, 0});

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string s = InputWheel();
            forbidden_.insert(s);
        }
    }

    int Play() {
        if (start_ == target_) {
            return 0;
        }
        while (!bfs_.empty()) {
            auto s = bfs_.front();
            bfs_.pop();
            auto res = TurnTheWheel(s);
            if (res > 0) return res;
        }

        return -1;
    }

    ~Wheels() = default;

private:
    class Step;
    int TurnTheWheel(const Step& step) {
        auto s = step.str_;
        auto i = 0;
        auto direct = -1;


        while (i < 4) {
            auto j = static_cast<int>(s[i] - 48 + direct);
            if (j < 0) j = 9;
            if (j > 9) j = 0;

            string new_str = s;
            new_str[i] = static_cast<char>(j + 48);
            if (!forbidden_.count(new_str)) {
                if (new_str == target_) return step.s_+1;
                forbidden_.insert(new_str);
                bfs_.push(Step{new_str, step.s_+1});
            }
            if (direct > 0) {
                ++i;
            }
            direct = -direct;
        }

        return 0;
    }

    string InputWheel() {
        string s;
        for (int i = 0; i < 4; ++i) {
            int j;
            cin >> j;
            s = s + static_cast<char>(j+48);
        }

        return s;
    }

    class Step {
    public:
        Step(const string& str, int s): str_(str), s_(s) {}
        int s_ = 0;
        string str_;
    };

    string start_;
    string target_;

    unordered_set<string> forbidden_;
    queue<Step> bfs_;
};

int main() {
    int n ;

    cin >> n;
    while(n--) {
        Wheels w;
        cout << w.Play() << endl;
    }

    return 0;
}
