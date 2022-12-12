/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: lc_1531.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 10-28-2022 16:30:26
 * @version $Revision$
 *
 **************************************************************************/

#include <any>
#include <variant>
#include <optional>
#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <limits>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    //using vec_any = vector<std::any>;
    //using last_chars_pair = pair<int, set<string>>;
    //using last_chars_hash = multimap<char, last_chars_pair>;

    using set_str = set<string>;

    string compress(const string &s, char cur_ch) {
        auto l = s.size();
        auto count_str = 0;
        auto c = 1;
        for (auto i = l-1; i >=0; --i) {
            if (s[i] >= '0' && s[i] <= '9') {
                count_str += (s[i] - '0') * c;
                c *= 10;
            } else {
                if (count_str == 0) { count_str = 1;};
                if (s[i] == cur_ch) {
                    count_str++;
                    return s.substr(0, i+1) + to_string(count_str);
                } else {
                    return s + cur_ch;
                }
            }
        }
    }

    void recompress(string &s, int last_pos) {
        char s1;
        auto count_s1 = 0;
        auto pos = 0;

        for (auto i = last_pos-1; i >= 0; --i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s1 = s[i];
                pos = i;
                break;
            }
        }
        char s2 = s[last_pos];
        if (s1 != s2) return;

        if (last_pos-pos-1 == 0) {
            count_s1 = 1;
        } else {
            count_s1 = std::stoi(s.substr(pos+1, last_pos-pos-1));
        }
        auto pos_s1 = pos;

        auto count_s2 = 0;
        for (auto i = last_pos+1; i < s.size(); ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                pos = i;
                break;
            }
        }
        if (pos-last_pos-1 == 0) {
            count_s2 = 1;
        } else {
            count_s2 = std::stoi(s.substr(last_pos+1, pos-last_pos-1));
        }

        s = s.substr(0, pos_s1+1) + to_string(count_s1+count_s2) + s.substr(pos);
    }

    set_str extra_del(const string &s) {
        auto last_ch = s[0];
        auto last_pos = 0;
        auto count_str = 0;
        auto str = s;
        set_str r;
        auto min_len = std::numeric_limits<int>::max();

        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                count_str = count_str*10 + s[i]-'0';
            } else {
                if (s[i] != last_ch) {
                    if (count_str == 2) {
                        str.erase(last_pos+1,1);
                    } else if (count_str == 0) {
                        str.erase(last_pos, 1);
                        recompress(str, last_pos);
                    } else if (count_str == 10) {
                        str.erase(last_pos+1,1);
                        str[last_pos+1] = '9';
                    } else {
                        str = s.substr(0, last_pos+1) + to_string(count_str-1) + s.substr(i);
                        //cout << s << " " << str << endl;
                    }

                    if (str.size() <= s.size()) {
                        if (str.size() == min_len) {
                            r.insert(std::move(str));
                        } else if (str.size() < min_len) {
                            min_len = str.size();
                            r = {std::move(str)};
                        }
                        str = s;
                    }

                    last_ch = s[i];
                    last_pos = i;
                    count_str = 0;
                }
           }
        }

        if (count_str != 0) {
            str = s.substr(0, last_pos+1);
            if (count_str != 2) {
                str += to_string(count_str-1);
            }
            if (r.empty() || r.begin()->size() == str.size())
                r.insert(std::move(str));
        }

        return r;
    }

    set_str calc(const set_str& v, const char cur_ch, bool can_del=false) {
        set_str r;
        auto min_len = std::numeric_limits<int>::max();

        for (auto &&item : v) {
            string s;
            if (item[item.size()-1] >= 'a'
                && item[item.size()-1] <= 'z'
                && item[item.size()-1] != cur_ch) {
                if (item.size()+1 > min_len && !can_del) continue;

                s = item + cur_ch;
            } else {
                s = compress(item, cur_ch);
            }

            //s = compress(item, cur_ch);

            set_str extra_r;

            if (can_del && s.size() == item.size()) {
                extra_r = extra_del(s);
            } else if (can_del) {
                extra_r = {item};
            } else {
                extra_r = {s};
            }

            if (extra_r.begin()->size() < min_len) {
                min_len = extra_r.begin()->size();
                r = std::move(extra_r);
            }else if (extra_r.begin()->size() == min_len) {
                r.merge(extra_r);
            }
        }

        if (r.empty())
            r.insert(string{""}+cur_ch);

        return r;
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {

        auto l = s.length();
        if (k == l) {
            return 0;
        }

        vector<vector<set_str>> res{l+1, vector<set_str>{static_cast<size_t>(k+1)}};

        res[1][0] = {s.substr(0,1)};
        /*
        if (k > 0) {
            res[1][1] = {}
        }*/

        for (auto i = 2; i <= s.size(); ++i) {
            auto cur_ch = s[i-1];

            for(auto j = 0; j <= k; ++j) {
                if (i == j) {
                    res[i][j] = {};
                    break;
                }

                auto cur_res = calc(res[i-1][j], cur_ch);

                if (j > 0) {
                    auto cur_res2 = calc(res[i-1][j-1], cur_ch, true);
                    if (cur_res.begin()->size() == cur_res2.begin()->size()) {
                        cur_res.merge(cur_res2);
                    } else if (cur_res.begin()->size() > cur_res2.begin()->size()) {
                        cur_res = std::move(cur_res2);
                    }
                }

                res[i][j] = std::move(cur_res);
            }
        }

        return res[s.size()][k].begin()->size();
    }
};


int main() {
    /*
    auto kv = make_pair<int, int>(0, 1);

    auto any1 = std::any(make_pair<char, bool>('a', true));

    cout << "type: " << any1.type().name() << endl;

    pair<char, bool> p('c', true);

    auto p1 = std::any_cast<pair<char, bool>>(any1);

    cout << std::get<0>(p1) << endl;
    cout << std::get<1>(p1) << endl;



    vector<std::any> v1 {1, 2, make_pair<char, bool>('c', false), std::any{std::in_place_type<pair<int, float>>, 3, 3.5f}};

    auto any2 = std::any(std::in_place_type<int>, 1);

    auto var1 = std::variant<float, int, bool>(std::in_place_index<2>, true);
    auto var2 = std::variant<float, int, bool>(std::in_place_type<bool>, true);

    auto opt1 = std::optional<float>(std::in_place, 5.3f);


    string str = "hello";
    str[1] = 'f';

    auto any3 = std::any(str[1]);
    cout << "type: " << any3.type().name() << endl;

    std::initializer_list<std::any> l{1,2,3, make_pair<char, bool>(static_cast<char>(str[1]), false)};
    //std::initializer_list<std::any> l{1,2,3, make_pair(str[1], false)};

    auto p4 = pair<char, bool>(str[1], false);

    int a[2]{1,2};
    auto p5 = make_pair(a[1], true);

    for (auto a : l) {
    try {
        cout << std::any_cast<int>(a) << endl;
    }
    catch (const std::bad_any_cast& e){
        cout <<  std::any_cast<pair<char, bool>>(a).first << endl;
    }
    }
    */

    Solution s;
    //cout << s.getLengthOfOptimalCompression("aaa", 1) << endl;
    //cout << s.getLengthOfOptimalCompression("aaa", 2) << endl;
    //cout << s.getLengthOfOptimalCompression("aaa", 3) << endl;
    //cout << s.getLengthOfOptimalCompression("aaabcccd", 2) << endl;

    /*
    cout << s.getLengthOfOptimalCompression("aaabaaa", 1) << endl;
    cout << s.getLengthOfOptimalCompression("aabaa", 1) << endl;

    cout << s.getLengthOfOptimalCompression("aaabbaaa", 2) << endl;
    cout << s.getLengthOfOptimalCompression("aaabbaaaaaaa", 3) << endl;
    cout << s.getLengthOfOptimalCompression("aaabbaaaaaaaa", 3) << endl;
    cout << s.getLengthOfOptimalCompression("a", 0) << endl;
    cout << s.getLengthOfOptimalCompression("aaaaaaaaaaa", 0) << endl;
    cout << s.getLengthOfOptimalCompression("aaaaaaaaaaabbb", 0) << endl;
    */

    /*cout << s.getLengthOfOptimalCompression("eceeebacbdcccaadcaa", 6) << endl;  // 7
    cout << s.getLengthOfOptimalCompression("bacbdcccaadcaa", 6) << endl;  // 4
    cout << s.getLengthOfOptimalCompression("bacbdccaadcaa", 5) << endl;   // 5
    cout << s.getLengthOfOptimalCompression("cbdccceccc", 3) << endl; // 2
    cout << s.getLengthOfOptimalCompression("bacbdccceefcee", 5) << endl; //5
    cout << s.getLengthOfOptimalCompression("bacbdcccaadcaa", 4) << endl;  //6
    */

    cout << s.getLengthOfOptimalCompression("ddadccabecddcdbdcaceaceedbebeaadddadcedebbeaedabbcddddecbdaaeeceeebacbacdcccaadcdbaaadcbbab", 56) << endl;
    //cout << s.getLengthOfOptimalCompression("ddadccabecddcdbdcaceaceedbebeaadddadcedebbeaedabbcddddecbdaaeeceeebacbacdcccaadcdbaaadcbbabbacea", 56) << endl;
    //cout << s.getLengthOfOptimalCompression("ababa", 2) << endl;
    //cout << s.getLengthOfOptimalCompression("abcdefabcdefa", 10) << endl;
    //cout << s.getLengthOfOptimalCompression("aaaaabaaaaaacaaaa", 15) << endl;


    return 0;
}
