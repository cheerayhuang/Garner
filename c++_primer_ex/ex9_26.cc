#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main() {
    int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    vector<int> vec{begin(a), end(a)};
    list<int> l(a, a+11);

    auto iterVec = vec.begin();
    while(iterVec != vec.end()) {
        if (*iterVec % 2 == 0) {
            iterVec = vec.erase(iterVec);
        } else {
            iterVec++;
        }
    }

    auto iterList = l.begin();
    while(iterList != l.end()) {
        if (*iterList % 2) {
            iterList = l.erase(iterList);
        }else {
            iterList++;
        }
    }

    for (auto i : vec) {
        cout << i << endl;
    }

    for (auto i : l) {
        cout << i << endl;
    }

    return 0;
}
