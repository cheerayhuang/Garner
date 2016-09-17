/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: algorithm.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 08-27-2016 09:34:09
 * @version $Revision$
 *
 **************************************************************************/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {

    vector<int> a = {2, 3, 5, 7 , 9};

    cout << "all_of:" << endl;
    cout << all_of(a.begin(), a.end(), [](int i) { return i%2; }) << endl;
    cout << "any_of:" << endl;
    cout << any_of(a.begin(), a.end(), [](int i) { return i%2; }) << endl;
    cout << "none_of:" << endl;
    cout << none_of(a.begin(), a.end(), [](int i) { return i%2; }) << endl;

    for_each(a.begin(), a.end(), [](int &i) {i++;});
    cout << "for_each:" << endl;
    for_each(a.begin(), a.end(), [](int &i) {cout << i << endl;});

    cout << "find:" << endl;
    cout << *find(a.begin(), a.end(), 3) << endl;

    cout << "find_if:" << endl;
    cout << *find_if(a.begin(), a.end(), [](int i) { return i % 2 ==0; }) << endl;
    cout << "find_if_not:" << endl;
    cout << *find_if_not(a.begin(), a.end(), [](int i) { return i % 2 ==0; }) << endl;

    vector<int> b = {8};
    vector<int> c = {7, 8, 7, 8, 7, 8};
    cout << "find_end:" << endl;
    cout << (find_end(c.begin(), c.end(), b.rbegin(), b.rend())- c.begin()) << endl;
    cout << "find_first_of:" << endl;
    cout << (find_first_of(c.begin(), c.end(), b.begin(), b.end())- c.begin()) << endl;

    vector<int> d = {7, 7};
    cout << "adjacent_find:" << endl;
    cout << *adjacent_find(d.begin(), d.end()) << endl;

    cout << "count:" << endl;
    cout << count(d.begin(), d.end(), 7) << endl;
    cout << "count_if:" << endl;
    cout << count_if(d.begin(), d.end(), [](int i) { return i != 7; }) << endl;

    c.assign({7, 7});
    auto r = mismatch(c.begin(), c.end(), d.begin());
    cout << "mismatch:" << endl;
    cout << r.first - c.begin() << ' ' << r.second - d.begin() << endl;

    cout << equal(c.begin(), c.end(), d.begin()) << endl;

    c.assign({1, 2, 3});
    d.assign({1, 3, 2});
    cout << equal(c.begin(), c.end(), d.begin()) << endl;
    cout << "is_permutation:" << endl;
    cout << is_permutation(c.begin(), c.end(), d.begin()) << endl;

    d.assign({1, 2, 3, 4});
    cout << "search:" << endl;
    cout << (search(c.begin(), c.end(), d.begin(), d.end()) == c.end()) << endl;
    cout << "search_n:" << endl;
    cout << (search_n(c.begin(), c.end(), 4, 4, [](int i, int j) { return i < j; }) == c.end()) << endl;

    vector<int> e;
    cout << "copy:" << endl;
    copy(d.begin(), d.end(), back_inserter(e));
    cout << "transform:" << endl;
    transform(e.begin(), e.end(), e.begin(), [](int i) { cout << i << endl; return i;}); // reture value is required.
    cout << "copy_n:" << endl;
    ostream_iterator<int> o(cout, "\n");
    copy_n(e.begin(), 2, o);
    cout << "copy_if:" << endl;
    copy_if(e.begin(), e.end(), o, [](int i)->bool { return i < 4; });

    cout << "copy_backward:" << endl;
    e.assign({1,2,3,4,5,6,7,8});
    copy_backward(d.begin(), d.end(), e.end());
    copy(e.begin(), e.end(), o);

    cout << "move_backward:" << endl;
    d.assign({8, 7, 6, 5});
    move_backward(d.begin(), d.end(), e.end());
    copy(e.begin(), e.end(), o);

    cout << "swap ranges:" << endl;
    d.resize(8);
    swap_ranges(e.begin(), e.end(), d.begin());
    copy(e.begin(), e.end(), o);

    cout << "replace:" << endl;
    vector<string> s_vec = {"hello", "hello", "beijing"};
    replace(s_vec.begin(), s_vec.end(), string("hello"), string("chengdu"));
    auto o_str = ostream_iterator<string>(cout, "\n");
    copy(s_vec.begin(), s_vec.end(), o_str);

    cout << "replace_if:" << endl;
    replace_if(s_vec.begin(), s_vec.end(), [](const string& s) { return s == "chengdu";}, string("hello"));
    copy(s_vec.begin(), s_vec.end(), o_str);

    cout << "replace_copy:" << endl;
    replace_copy(s_vec.begin(), s_vec.end(), o_str, string("hello"), string("hi,"));

    cout << "replace_copy_if:" << endl;
    replace_copy_if(s_vec.begin(), s_vec.end(), o_str, [](const string& s) { return s == "hello";}, string("helloo"));

    cout << "fill:" << endl;
    fill(s_vec.begin(), s_vec.end(), "morning");
    copy(s_vec.begin(), s_vec.end(), o_str);

    cout << "fill_n" << endl;
    fill_n(s_vec.begin(), 2, "afternoon");
    copy(s_vec.begin(), s_vec.end(), o_str);

    cout << "generate:" << endl;
    generate(s_vec.begin(), s_vec.end(), []()->string { return "h"; });
    copy(s_vec.begin(), s_vec.end(), o_str);

    cout << "generate_n:" << endl;
    generate_n(s_vec.begin(), 1, []()->string { return "k"; });
    copy(s_vec.begin(), s_vec.end(), o_str);

    cout << "remove_copy:" << endl;
    remove_copy(s_vec.begin(), s_vec.end(), o_str, "k");

    cout << "remove_copy_if:" << endl;
    remove_copy_if(s_vec.begin(), s_vec.end(), o_str, [](string& s) { return s == "h"; });

    cout << "unique:" << endl;
    auto s_vec_new_end = unique(s_vec.begin(), s_vec.end());
    copy(s_vec.begin(), s_vec_new_end, o_str);

    cout << "unique_copy:" << endl;
    vector<string> v_str2(8);
    auto v_str2_end = unique_copy(s_vec.begin(), s_vec.end(), v_str2.begin());
    cout << distance(v_str2.begin(), v_str2_end) << endl;

    cout << "reverse:" << endl;
    reverse(d.begin(), d.end());
    copy(d.begin(), d.end(), o);

    cout << "reverse_copy:" << endl;
    reverse_copy(d.begin(), d.end(), o);

    cout << "rotate_copy:" << endl;
    rotate_copy(d.begin(), d.begin()+3, d.end(), o);


    return 0;
}

