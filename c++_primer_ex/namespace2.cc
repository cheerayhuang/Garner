#include "namespace.h"

namespace test {
    void func2() {
        cout << "hello func2" << endl;
    }

    void func3() {
        func();
    }

    namespace {

        void func4() { cout << "hello func4" << endl; }

    }

    int k = 1024;
}
