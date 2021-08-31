#include <string>
#include <functional>
#include <iostream>
#include <optional>

#include <vector>
#include <type_traits>

using std::cout;
using std::endl;


// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {};
}

// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}

// std::reference_wrapper may be used to return a reference
auto create_ref(bool b) {
    static std::string value = "Godzilla";
    return b ? std::optional<std::reference_wrapper<std::string>>{value}
             : std::nullopt;
}


std::reference_wrapper<int> func() {
   int i = 1024;

   return i;
}

void handle_ref(int &) {
    cout << "int l-ref" << endl;
}

void handle_ref(int &&) {
    cout << "int r-ref" << endl;
}

template<typename T>
void temp_1(T&) = delete; /*{
    cout << "ref" << endl;
}*/

template<typename T>
void temp_1(T&&) {
    cout << "rref" << endl;
}

class A {
    public:
        operator int& () {
            static int i;
            return i;
        }

};

template<typename T, typename = std::enable_if_t<std::is_same_v<int, T>>>
class B {

};

int main()
{
    std::cout << "create(false) returned "
              << create(false).value_or("empty") << '\n';

    // optional-returning factory functions are usable as conditions of while and if
    if (auto str = create2(false)) {
        std::cout << "create2(false) returned " << *str << '\n';
    }

    if (auto str = create_ref(true)) {
        // using get() to access the reference_wrapper's value
        std::cout << "create_ref(true) returned " << str->get() << '\n';
        str->get() = "Mothra";
        std::cout << "modifying it changed it to " << str->get() << '\n';
    }

    int j;
    int &rj = j;
    auto rw = std::reference_wrapper<int>{rj};

    int &rj2 = rw;
    std::cout << rw.get() << std::endl;
    std::cout << rw.get() << std::endl;


    int i = 5;
    int &ri = i;
    handle_ref(std::forward<decltype(rw.get())>(rw.get()));
    handle_ref(std::forward<decltype(ri)>(ri));

    handle_ref(rw);

    std::reference_wrapper<int> rwi = i;

    A a;

    int &ri3 = a;

    B<int> b1;
    //B<double> b2;

    std::optional<int> o = std::nullopt;
    if (!o) {

        std::cout << "hello" << std::endl;
    }

    //temp_1(rw);
}
