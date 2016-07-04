/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex14_38.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-04-2016 21:30:03
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std;

class CountLetters {

public:
    CountLetters(int beg=0, int end=-1) : sz_beg(beg), sz_end(end) { }

public:
    bool operator()(const string & s) {
        if (sz_end == -1) {
            return s.length() > sz_beg;
        }

        return s.length() >= sz_beg && s.length() <= sz_end;
    }

private:
    int sz_beg = 0;
    int sz_end = -1;

public:
    int k = 1024;

};

bool CountWord(const string &s, int sz_beg, int sz_end) {
    return s.length() >= sz_beg && s.length() <= sz_end;
}

int main() {
    ifstream fin("ex14_38.cc");

    istream_iterator<string> iter_fin(fin), iter_fin_end;
    ostream_iterator<string> iter_cout(cout);

    vector<string> text;
    copy(iter_fin, iter_fin_end, inserter(text, text.end()));

    fin.close();

    auto t =  count_if(text.begin(), text.end(), CountLetters(10));
    cout << t << endl;

    t = count_if(text.begin(), text.end(), CountLetters(1, 9));
    cout << t << endl;

    cout << CountLetters(1,9).k << endl;

    using namespace std::placeholders;

    auto count_word_fn = bind(CountWord, _1, 1, 9);
    t = count_if(text.begin(), text.end(), count_word_fn);
    cout << t << endl;

    return 0;
}
