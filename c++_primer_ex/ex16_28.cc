#include <iostream>

using namespace std;

template<typename T>
void func(T *p);

template <typename T>
class shared_ptr {
public:
    void (*del) (T*) = func<T>;

    shared_ptr(T* p, void (*func)(T*)) {
        ptr = p;
        del = func;
    }

    shared_ptr(): ptr(nullptr), del(nullptr) {}

    ~shared_ptr() {
        del ? del(ptr) : delete ptr;
    }

private:
    T * ptr;
};


class A {
public:
    A() { cout << "construct A" << endl; }
    ~A() { cout << "destruct A" << endl; }
};

template <typename T>
void func(T *p) { delete p; }

int main() {

    shared_ptr<A> s(new A(), func<A>);


    return 0;
}
