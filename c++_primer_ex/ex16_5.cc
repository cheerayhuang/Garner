#include <iostream>

using namespace std;


template <typename T, unsigned N>
void print(T (&arr) [N]) {
    arr[1] = 1024;
    for (auto i : arr) {
        cout << i << endl;
    }
}

/*template <typename T>
void print(T * arr, unsigned n) {
    arr[1] = 1024;
    for(auto i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}*/

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    print(a);

    return 0;
}
