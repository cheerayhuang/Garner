#include <iostream> 
#include <list>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int main() {
    
    list <char*> l {"a", "b", "c"};
    
    char *ch = new char[10];
    strcpy(ch, "hello");

    l.assign(5, ch);
    for (auto c : l) {
        cout << c << endl;
    }

    vector<string> vec;
    vec.assign(l.begin(), l.end());

    delete []ch;
    ch = nullptr;
    
    for (auto c : vec) {
        cout << c << endl;
    }

    vec[1] = "abc";

    for (auto c : vec) {
        cout << c << endl;
    }

    return 0;
}
