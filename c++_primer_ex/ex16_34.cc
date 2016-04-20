#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

template <typename T>
class TD;

template <typename T>
int compare(const T, const T) { cout << sizeof(T) << endl; return 0; }

template <typename T>
void f1(T x, T) {TD<decltype(x)> t1; }

template <typename T1, typename T2>
void f2(T1, T2) {}


template <typename T>
auto fcn3(T beg, T end) -> decltype(*beg, 0)
{
    return *beg;
}

int main() {

    compare("hi", "hello");

    cout << sizeof(int*) << endl;


    int i = 0, j = 42, *p1 = &i, *p2 = &j;
    const int *cp1 = &i, *cp2 = &j;

    int &ri = i;
    const int &cri = i;

    //f1(p1, p2);
    //f2(p1, p2);
    //f1(cp1, cp2);
    //f2(cp1, cp2);
    //f1(cp1, p1);
    //f2(p1, cp1);

    //f1(ri, cri);
    //f1(i, j);

    const int k = 10;
    f1(k, j);
    f1(5*10, j);

    vector<int> v = {1, 2, 3};
    cout << fcn3(v.begin(), v.end()) << endl;

    return 0;
}
