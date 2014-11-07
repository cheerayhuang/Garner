/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex11_31.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 16:08:06
 * @version $Revision$
 *
 **************************************************************************/

#include <map> 
#include <iostream> 
#include <fstream> 
#include <iterator>

using namespace std; 

int main() {
    
    fstream fin("ex11_31.txt");
    istream_iterator<string> is_iter(fin), eof;

    multimap<string, string> authors;

    while (is_iter != eof) {
        auto key = *is_iter++;
        auto val = *is_iter++;

        authors.insert(make_pair(key, val));
    }

    fin.close();

    auto pos = authors.find("d");
    if (pos != authors.end()) {
        auto c = authors.count("d");
        while (c--) {
            authors.erase(pos++);
        }
    }
    
    auto key = string("");

    for(auto &i : authors) {
        if (key == i.first) continue;
        key = i.first;
        cout << key << ":" << endl;
        for(auto range = authors.equal_range(key); range.first != range.second; ++range.first) {
           cout << "\t" << range.first->second << endl; 
        }
    }

    return 0;
}

