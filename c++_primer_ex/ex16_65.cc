#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
string DebugRep(const T& t) {
    ostringstream out;

    out << t;

    return out.str();
}

/*
template<typename T>
string DebugRep(T* p) {
    ostringstream out;
    out << "Pointer: " << p;
    if (p) {
        out << " " << DebugRep(*p);
    }
    else {
        out << " null pointer";
    }

    return out.str();
}
*/

string DebugRep(const string &s) {
    return '"' + s + '"';
}

/*template<>
string DebugRep<const char>(const char *p) {
    return DebugRep(string(p));
}*/

template<>
string DebugRep<const char*>(const char* const &t) {
    return DebugRep(string(t));
}

int main() {
    int i = 10;
    cout << DebugRep(i) << endl;

    int *pi = &i;
    cout << DebugRep(pi) << endl;

    cout << DebugRep(static_cast<const char*>("hello world!")) << endl;

    return 0;
}
