#include <iostream>

using namespace std;


int part(int *a, int start, int end, int n) {
    auto x = a[start];
    auto i = start + 1;
    auto j = end - 1;

    while (i < j) {
        while (i < end && a[i] <= x) i++;
        while (a[j] > x && j > start) j--;

        if (i < j)
            swap(a[i], a[j]);
    }

    i = j;
    swap(a[start], a[i]);

    auto k = i - start + 1;

    if (k > n) {
        return part(a, start, i, n);
    }

    if (k < n) {
        return part(a, i+1, end, n-k);
    }

    return x;
}

int main() {
    int a[10] {2, 5, 1, 3, 4, 6, 7, 8, 9};
    int b[10] {1, 2, 3, 4, 5, 9, 8, 7, 6};
    int c[10] {5, 8, 6, 4, 7, 3, 2, 9, 1};
    int d[10] {9, 8, 4, 1, 3, 2, 6, 7, 5};

    cout << part(a, 0, 9, 3) << endl;
    cout << part(b, 0, 9, 2) << endl;
    cout << part(c, 0, 9, 4) << endl;
    cout << part(d, 0, 9, 5) << endl;

    const int i = 10;
    //i = 9;

    auto &j = i;
    //j = 9;

    cout << i << endl;
    cout << j <<endl;
    cout << std::is_reference_v<decltype(j)> << endl;

    auto k = &i;
    cout << *k <<endl;
    // *k = 11;
    k = &j;

    auto l = 1;
    auto m = &l;
    *m = 2;

    return 0;
}
