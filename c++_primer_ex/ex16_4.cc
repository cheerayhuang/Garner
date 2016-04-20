#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template <typename IT, typename T>
size_t find(IT beg, IT end, const T& v) {
    for (auto i = beg; i != end; ++i) {
        if (*i == v) {
            return i-beg;
        }
    }
    return -1;
}

int main() {

    vector<int> v = {1, 2, 3, 4};
    list <string> l = {"hello", "world", "city"};

    cout << find(v.begin(), v.end(), 3) << endl;
    // error, since list::iterator is a bid-iterator not a random-iterator.
    //cout << find(l.begin(), l.end(), "world") << endl;

    cout << find(v.begin(), v.end(), 7) << endl;

    return 0;
}
