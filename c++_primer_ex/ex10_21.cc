#include <iostream> 

using namespace std; 

int main() {
    int i = 50; 

    auto func = [&i]() mutable ->bool { 
                int k =10;
                if (i == 0) return true;  
                --i; --k; 
                cout << i << endl;
                cout << k << endl;
                return false; 
    };

    while ( !func() ) {
    }

    cout << i << endl;

    return 0;
}
