#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <sstream>
#include <algorithm>
#include <iterator>


using namespace std;

class QueryResult;

class TextQuery {
private:
    shared_ptr<vector<string>> text;
    map<string, shared_ptr<set<size_t>>> dir;

public:
    TextQuery(ifstream &infile);

    QueryResult query(const string& s);
};

TextQuery::TextQuery(ifstream &infile) : text(new vector<string>()) {

    string line;
    while (getline(infile, line)) {
        text->push_back(line);
        string tmp(line.length(), char());
        transform(line.begin(), line.end(), tmp.begin(), [](char ch) -> char { if ((ch < 65 || (ch > 90 && ch < 97) || ch > 122) && ch != ' ') return char(); return ch;});
        istringstream iss(tmp);
        string s;
        while(iss >> s) {
            if (dir.find(s) == dir.end()) {
                dir[s] = make_shared<set<size_t>>(set<size_t>{text->size()});
            }
            else {
                dir[s]->insert(text->size());
            }
        }
    }
}

class QueryResult {

private:
    shared_ptr<vector<string>> text;
    string word;
    shared_ptr<set<size_t>> lines;

public:
    QueryResult(shared_ptr<vector<string>> &t, const string &s, shared_ptr<set<size_t>> l)
        :text(t), word(s), lines(l) {
    }

    friend ostream& print(ostream &os, const QueryResult &result);
};

QueryResult TextQuery :: query(const string& s) {
    auto pos = dir.find(s);
    if (pos != dir.end()) {
        return QueryResult(text, s, pos->second);
    }

    return QueryResult(text, s, make_shared<set<size_t>>());
}

void runQueries(ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

ostream& print(ostream &os, const QueryResult &result) {
    if (result.lines->empty()) {
        os << result.word << " : Not found!";
        return os;
    }

    os << result.word << " occurs " << result.lines->size() << " times:" << endl;

    for (auto i : *result.lines) {
        os << i << ": " << result.text->at(i-1) << endl;
    }

    return os;
}

int main() {
    ifstream fin("1.txt");
    runQueries(fin);
    return 0;
}
