#include <iostream>
#include <algorithm>
#include <vector> 
#include <string> 

using namespace std;

void biggies(vector<string> &words, 
             vector<string>::size_type sz)
{
    stable_sort(words.begin(), words.end());
    unique(words.begin(), words.end());
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });

    auto pos = find_if(words.begin(), words.end(), [&sz](const string &a){ return a.size() >= sz; });

    for_each(pos, words.end(), [](const string &s){ cout << s << " "; });

    cout << endl;
}

int main() {
    vector<string> v; 

    string str;
    while(cin >> str) {
        v.push_back(str);
    }
    biggies(v, 4);

    return 0;
}

