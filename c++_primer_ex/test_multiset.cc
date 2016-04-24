#include <set>
#include <string>
#include <iostream>

using namespace std;


class A {
    public:
        int v = 10;

};

bool CompareA(const A& lhs, const A& rhs) { return true; }

void func(decltype(CompareA) fn) {
    if (fn(A(), A())) {
        cout << "fn type is function type, converting to function pointer type" << endl;
    }
}

int main() {


    string s1;
    string s2;
    multiset<string> mset_str;
    mset_str.insert(s1);
    mset_str.insert(s2);

    A a;
    A a2;
    multiset<A, decltype(CompareA)*> mset{CompareA};
    mset.insert(a);
    mset.insert(a2);

    func(CompareA);

    // wrong: since decltype(CompareA) is a function type, fn is a function , not a pointer variable.
    // "CompareA" is just converted to function pointer when it is used as a value.
    // function type is just converted to function pointer type when it is used as the param in a function.
    //decltype(CompareA) fn = CompareA;

    typedef bool ComA(const A& lhs, const A& rhs);
    ComA* fn = CompareA;

    cout << fn(A(), A()) << endl;

    return 0;
}
