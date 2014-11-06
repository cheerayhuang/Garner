#include <iostream> 
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 
using namespace placeholders;

bool CheckSize(const string &str, string::size_type sz) {
    return str.size() <= sz;
}

int main() {
    vector<string> v;
    
    string str;
    while(cin >> str) {
        v.push_back(str);
    }

    cout << count_if(v.begin(), v.end(), bind(CheckSize, _1, 6)) << endl; 

    return 0;
}
