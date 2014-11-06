#include <iostream> 
#include <algorithm>
#include <string> 
#include <vector>

using namespace std; 

bool func(string &str) {
    return str.size() < 5;
}

int main() {

    vector<string> words;

    string str;
    while(cin >> str) {
        words.push_back(str);
    }

    auto pos = partition(words.begin(), words.end(), func);

    while (pos != words.end()) {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;

    return 0;
}

