#include <iostream>

using namespace std;

template<unsigned H, unsigned W>
class Screen;

template<unsigned H, unsigned W>
ostream& operator<<(ostream &os, const Screen<H, W> &);

template <unsigned H, unsigned W>
class Screen {
    public:
        // authorized specified instance to be friend.
        friend ostream& operator<< <H, W>(ostream &, const Screen<H, W>&);

        // authorized all instances to be friend.
        template <unsigned M, unsigned N>
        friend ostream& operator<< (ostream &, const Screen<M, N>&);

        // this func is not a template func!
        friend ostream& operator<< (ostream &os, const Screen<H, W> &s) {
            for (auto i = 0; i < H; ++i) {
                for (auto j = 0; j < W; ++j)
                    cout << "*";
                    cout << "\n";
            }

            return os;
        }
};

template<unsigned H, unsigned W>
ostream& operator<<(ostream &os, const Screen<H, W>&) {
    cout << "external one:" << endl;
    for (auto i = 0; i < H; ++i) {
        for (auto j = 0; j < W; ++j)
            cout << "*";
            cout << "\n";
        }

    return os;
}

class A {
        friend ostream& operator<<(ostream& os, const A &) {
            cout << "hello world";
            return os;
        }
};

ostream& operator<<(ostream &os, const A*) {
    cout << "hello chengdu";
    return os;
}

template <unsigned M, unsigned N> using S = Screen<M, N>;
template <unsigned M> using Sc3 = Screen<M, 7>;

int main(){

    S<5, 4> s;
    cout << s;

    typedef Screen<5,5> Sc;
    Sc s2;
    cout << s2;

    using Sc2 = Screen<6, 6>;
    Sc2 s3;
    cout << s3;


    Sc3<10> s4;
    cout << s4;


    A obj_a;
    cout << obj_a << endl;
    cout << &obj_a << endl;
}
