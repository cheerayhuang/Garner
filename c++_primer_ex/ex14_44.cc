/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ex14_44.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-04-2016 23:00:31
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include <map>

using namespace std;

int Multiplies(int i, int j) { return i*j; };

class Calc {

public:
    Calc() {
        class add {
        public:
            int operator()(int i, int j) { return i+j;}
        };
        auto substract = [](int i, int j)->int { return i - j;};
        auto div = divides<int>();

        compute['+'] = add();
        compute['-'] = substract;
        compute['*'] = Multiplies;
        compute['/'] = div;


    };

    ~Calc() = default;
    Calc(const Calc&) = delete;
    Calc& operator=(const Calc&) = delete;

    void Run() {

        string express;

        while(cin >> express) {
            auto p = express.find_first_of("+-*/");
            if (p != string::npos) {
                num1 = stoi(express.substr(0, p));
                num2 = stoi(express.substr(p+1));
                op = express[p];
            }
            else {

            }

            cout << compute[op](num1, num2) << endl;
        }
    }

private:
    int num1;
    int num2;
    char op;

    map<char, function<int(int, int)>> compute;
};


int main() {

    Calc c;
    c.Run();

    return 0;
}


