#include <iostream> 
#include <string>

using namespace std;

class Data {
private:
    size_t size;
    string contents;
    unsigned lastUpdated;

public:
    Data(size_t s, string c, unsigned l) : size{s}, contents{c}, lastUpdated{l} {
        cout << "Data(s, c, l)" << endl;
    }

    Data() : Data{0, "", 0} {
        cout << "Data()" << endl;
    }

    Data(size_t s):  Data(0, "", 0) {
        size = s;
        cout << size << endl;
    }
};

static Data d5;

int main() {
    
    Data d1 = Data{1, "a", 1};

    Data d2{5};

    Data d3{}; 

    static Data d4;

    return 0;
}

