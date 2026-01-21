#include <iostream>

using namespace std;

auto max(const auto& a, const auto& b){
    cout << "max1" << endl;
    return a > b? a : b;
}

template<typename T, typename T2>
auto max(const T& a, const T& b) {
    cout << "max2" << endl;
    return a > b ? a : b;
}

/*
template<typename T1, typename T2>
auto max(const T1& a, const T2& b) -> decltype(a > b ? a : b) {
    cout << "max3" << endl;
    return a > b ? a : b;
}*/

template <typename T1, typename T2>
decltype(true ? T1{} : T2{}) max4(const T1 &a, const T2& b) {
    cout << "max4" << endl;
    return a > b ? a : b;
}

template <typename T1, typename T2>
common_type_t<T1, T2> max5(const T1 &a, const T2& b) {
    cout << "max5" << endl;
    return a > b ? a : b;
}

int main() {

    cout << ::max(5, 4) << endl;
    cout << ::max(5.1, 4.2) << endl;
    cout << ::max4(5.1, 4) << endl;

    cout << ::max5(5.1f, 4) << endl;
    return 0;
}
