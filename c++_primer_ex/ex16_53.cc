#include <iostream>

using namespace std;

template <typename T>
void Print(const T& t) {
    cout << t << endl;
}

template <typename T, typename... ARGS>
void Print(const T& t, const ARGS&... args) {
    cout << t << endl;
    Print(args...);
}


// except class, others' definition shoud be written before.
/*template <typename T>
void Print(const T& t) {
    cout << t << endl;
}*/

template <typename T>
T& AddQuote(T &t) {
    T& t1 = t;
    return  t1;
}

template <typename T, typename... ARGS>
void ErrorMsg(const T& t, const ARGS&... args) {
    Print(t, AddQuote(args)...);
}

int main() {
    int i  = 10;

    double j = 10.1234567d;

    long k = 1024;

    long long l = 10240;

    const char * str = "hello";

    Print(i);

    Print(i, j);

    Print(i, j, k, l, str);

    /*class A {
    } a;

    Print(i, j, k, l, str, a);
    */

    cout << "---------" << endl;

    ErrorMsg(i, j, k, l, str);

    return 0;
}
