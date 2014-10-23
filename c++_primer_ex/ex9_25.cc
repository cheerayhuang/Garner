#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l{1, 2, 3, 4, 5};

    auto beg = l.begin();
    beg++;

    auto it = l.erase(beg, beg);

    for (auto i : l) {
        cout << i << endl;
    }

    cout << (it == beg) << endl;
   
    return 0;
}
