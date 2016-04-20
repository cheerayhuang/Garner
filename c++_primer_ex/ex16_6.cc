#include <iostream>
#include <algorithm>

using namespace std;

namespace my_iter {
    template <typename T, unsigned N>
    const T* begin(const T (&arr) [N]) {
        return &arr[0];
    }
}

template <typename T, unsigned N>
constexpr unsigned func(const T (&arr) [N]) {
    return N;
}

int main() {
    long a[5] = {1, 2, 3, 4, 5};

    //*(my_iter::begin(a)) = 1024;

    cout << a[0] << endl;

    cout << func(a) << endl;

    return 0;
}
