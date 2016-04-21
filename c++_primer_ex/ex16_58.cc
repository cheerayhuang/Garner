#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename... ARGS>
void EmplaceBack(T& c, ARGS&&...args) {
    c.emplace_back(std::forward<ARGS>(args)...);
}

int main() {

    vector<int> v = {1};

    EmplaceBack(v, 10);

    //v.emplace_back(int(10));

    for (auto i : v) {
        cout << i << endl;
    }

    return 0;
}
