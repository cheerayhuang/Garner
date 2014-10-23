#include <iostream> 
#include <list>
#include <vector>

using namespace std;

int main() {
    list<int> l(10, 10); 
    vector<int> vecInt(10, 10);

    vector<double> vecDouble(l.begin(), l.end());
    vector<double> vecDouble2(vecInt.begin(), vecInt.end());

    for (const auto& i : vecDouble) {
        cout << i << endl;
    }

    cout << (l.begin() != l.end()) << endl;
    
    return 0;
}
