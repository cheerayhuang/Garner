#include <iostream>
#include <string>

using namespace std;

int main() {
    auto c1 = cin.get();
    cout << c1 << endl;
    cin.unget();
    auto c2 = cin.get();

    cout << c2 << endl;

    string str(10, '\0');
    cin.readsome(&str[0], 10);

    return 0;
}
