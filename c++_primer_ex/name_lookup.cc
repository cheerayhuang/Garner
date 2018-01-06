/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: name_lookup.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 04-17-2016 22:50:28
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>

using namespace std;


using ext_type = double;

class Screen;

class Base {
    protected:
        int height = 0;

        using myfloat = float;

        // myfloat can't be found, cause the name is in parameter declaration, it can only be found before.
        void func(Base::myfloat) {}

        // this statement should be move up.
        //using myfloat = float;

};


class Screen: public Base {
public:
    using pos = std::string::size_type;
    using myfloat = float;

    void setHeight(pos);
    pos Height = 0;

    ext_type setWidth(pos);
    //using ext_type = int;
};

void Globalfunc();

ext_type Screen::setWidth(pos) {
    // only if this function is defined within class, it can be found .
    Globalfunc();
}

void Globalfunc() {
}


//int height;
Screen::pos verify(Screen::pos) {};

void Screen::setHeight(pos var) {
    height = verify(var);
}



/*void func1() {
    func2();
}

void func2() {}
*/

class B{

    static int i;

    public:
    void func() {
        cout << i << endl;
    }

};

int B::i;


int main() {
    B b;
    b.func();

    Screen sc;

    // c++ has a very strict rule to force you to declare a func.
    // in c, a implicit declaration will be generated.
    //foo();

    return 0;
}

/*
void foo() {

}*/
