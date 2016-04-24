#include <iostream>

using namespace std;

template <typename FN,  typename T1, typename T2>
void forwarder(FN fn, T1&& t1, T2&& t2) {
    fn(std::forward<T1>(t1), std::forward<T2>(t2));
}

void func1(int &i, double d) {
    ++i;
}

void func2(int &&i, double d) {
    i++;
}


int main() {

    int i = 10;
    forwarder(func1, i, 3.5);

    cout << i << endl;

    //forwarder(func2, std::move(i), 3.5);
    func2(std::move(i), 3.5);
    cout << i << endl;

    forwarder(func2, std::move(i), 3.5);
    cout << i << endl;

    return 0;
}
