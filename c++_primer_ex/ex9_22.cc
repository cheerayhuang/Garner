#include <vector> 
#include <iostream> 

using namespace std; 

int main() {
    vector<int> iv {2, 2, 2, 2, 2};

    vector<int>::iterator iter = iv.begin(), 
                          mid = iv.begin() + iv.size()/2;

    while (iter <  mid) {
        if (*iter == 2) {
            iter = iv.insert(iter, 4);
            mid = iv.begin() + iv.size()/2;
        }
        iter = iter +2;
    }

    for (auto & i : iv) {
        cout << i << endl;
    }

    return 0;
}
