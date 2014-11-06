#include <iostream> 
#include <functional>
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 
using namespace placeholders;

bool CheckSize(const string &str, string::size_type sz) {
    return str.size() < sz;
}

int main() {
    vector<int> v {1, 2, 3, 4, 6, 7 , 8, 9};
    
    string str;
    cin >> str;
    
    cout << *find_if(v.begin(), v.end(), bind(CheckSize, str, _1)) << endl; 

    return 0;
}

