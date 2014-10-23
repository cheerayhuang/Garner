#include <iostream> 
#include <vector>

using namespace std;

int main() {
    vector <int> vec(10);

    cout << vec.front() << endl;
    cout << *vec.begin() << endl;
    vec.resize(0);
    cout << vec[0] << endl;
    //cout << vec.at(0) << endl;

    return 0;
}
