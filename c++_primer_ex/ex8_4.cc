/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex8_4.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-23-2014 12:18:10
 * @version $Revision$
 *
 **************************************************************************/

#include <fstream> 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> file;

    ifstream fin("./ex8_4.cc");
    string line;
    while(getline(fin, line)) {
        file.push_back(line);
    }

    for (auto it = file.begin(); it != file.end(); ++it) {
        cout << *it << endl;
    }

    cout << "========================" << endl;

    file.resize(0);
    fin.close();

    fin.open("./ex8_4.cc");

    while(fin >> line) {
        file.push_back(line);
    }

    for (auto it = file.begin(); it != file.end(); ++it) {
        cout << *it << endl;
    }

    fin.close();
    return 0;
}

