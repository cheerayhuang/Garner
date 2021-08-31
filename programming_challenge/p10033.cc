#include <iostream>
#include <string>
#include <vector>
#include <array>
//#include <sstream>
#include <cassert>
#include <functional>
#include <unordered_map>
#include <tuple>

using namespace std;

using fsm_func = function<int(char, char)>;

unordered_map<char, fsm_func> fsm;
unordered_map<char, int> regs;

using code_type = std::tuple<char, char, char>;
vector<code_type> codes;

auto count_steps() -> decltype(5) {

    auto is_stop = false;
    size_t ip = 0;
    auto steps = 0;

    while (!is_stop) {
        auto r = fsm[std::get<0>(codes[ip])](std::get<1>(codes[ip]), std::get<2>(codes[ip]));
        if (r == 0) {
            is_stop = true;
        } else if (r > 1000) {
            ip = r % 1000;
        } else {
            ip++;
        }

        steps++;
    }

    return steps;
}

/*
tuple<char, char, int> a = make_tuple('a', 'b', 1);
auto && b = std::move(a);
*/

void init() {
    fsm['1'] = [](char, char) -> int {return 0;};
    fsm['2'] = [](char d, char n) -> int {
        auto v = static_cast<int>(n - 48);
        regs[d] = v;
        return 1;
    };

    fsm['3'] = [](char d, char n) -> int {
        auto v = static_cast<int>(n - 48);
        regs[d] += v;
        regs[d] %= 1000;
        return 1;
    };

    fsm['4'] = [](char d, char n) -> int {
        auto v = static_cast<int>(n - 48);
        regs[d] *= v;
        regs[d] %= 1000;
        return 1;
    };

    fsm['5'] = [](char d, char s) -> int {
        regs[d] = regs[s];
        return 1;
    };

    fsm['6'] = [](char d, char s) -> int {
        regs[d] += regs[s];
        regs[d] %= 1000;
        return 1;
    };

    fsm['7'] = [](char d, char s) -> int {
        regs[d] *= regs[s];
        regs[d] %= 1000;
        return 1;
    };

    fsm['8'] = [](char d, char a) -> int {
        auto memory_index = regs[a];

        auto c = codes[memory_index];
        string str {std::get<0>(c), std::get<1>(c), std::get<2>(c)};
        auto v = std::stoi(str);

        regs[d] = v;
        return 1;
    };

    fsm['9'] = [](char s, char a) -> int {
        auto memory_index = regs[a];

        //auto c = codes[memory_index];
        auto v = regs[s];
        codes[memory_index] = make_tuple(static_cast<char>(v/100+48), static_cast<char>((v/10)%10+48), static_cast<char>(v%10+48));

        return 1;
    };

    fsm['0'] = [](char d, char s) -> int {
        if (d == '0' && s == '0') {
            return 0;
        }

        if (regs[s]) {
            return 1000 + regs[d];
        }

        return 1;
    };
}

auto interpret(string code) -> std::tuple<char, char, char> {
    return make_tuple(code[0], code[1], code[2]);
}

int main() {

    init();

    int case_count = 0;
    string code;

    cin.tie(&cout);

    cin >> case_count;

    cin.ignore(1, '\n');
    std::getline(cin, code); // read a null line

    while (case_count--) {

        std::getline(cin, code);
        while (code.size() != 0) {
            auto c = interpret(std::move(code));
            //cout << std::get<0>(c) << std::get<1>(c) << std::get<2>(c) << endl;
            codes.push_back(std::move(c));

            std::getline(cin, code);
            //cout << "code.size=" << code.size() << endl;
        }

        //codes.resize(1000);
        codes.push_back(make_tuple('0', '0', '0'));
        cout << count_steps() << endl;
        codes.clear();
    }

    return 0;
}

