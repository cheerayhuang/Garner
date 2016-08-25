#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

template<typename T>
int count(const vector<T> &v, const T & value) {
    int c = 0;
    for (auto i : v) {
        if (i == value) {
            ++c;
        }
    }
    return c;
}

template<>
int count<double>(const vector<double> &v, const double &k) {

    int c = 0;
    for (vector<double>::const_iterator i = v.cbegin(); i != v.cend(); ++i) {
        if (fabs(*i-k) < 0.000001) {
            ++c;
        }
    }

    return c;
}

template<>
int count<char*>(const vector<char*> &v, char* const &value) {
    return 1024;
}

template<>
int count<const char*>(const vector<const char*> &v, const char* const &value) {
    int c = 0;
    string target(value);

    for (auto i : v) {
        string str(i);
        if (str == target) {
            ++c;
        }
    }

    return c;
}

int main() {
    vector<int> v_int = {1, 2, 3, 3, 3};

    vector<double> v_double = {1.0d, 3.577777787d, 3.577777797d, 4.1d};

    cout << count(v_int, 3) << endl;

    cout << count(v_double, 3.577777) << endl;

    char *chs1 = new char[6];
    strcpy(chs1, "hello");
    char *chs2 = new char[6];
    strcpy(chs2, "world");
    char *chs3 = new char[6];
    strcpy(chs3, "world");
    vector<char*> v_chars = {chs1, chs2, chs3};
    const char* ptr_chars = "world";
    cout << count(v_chars, chs3) << endl;

    delete chs1;
    delete chs2;
    delete chs3;

    return 0;
}
