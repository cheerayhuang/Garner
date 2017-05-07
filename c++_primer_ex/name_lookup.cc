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

class Base {
    protected:
        int height = 0;

};

class Screen: public Base {
public:
    using pos = std::string::size_type;

    void setHeight(pos);
    pos Height = 0;

    ext_type setWidth(pos);
    //using ext_type = int;
};


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

    return 0;
}

