/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: test_ref.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 09-01-2014 12:27:14
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 


class A {
    public:

        A(string str) { cout << "A::A(str)" << endl;}
        //A(const char *str) { cout << "A::A(const char *)" << endl;}
        A(int i) { cout << "A::A(int)" << endl; }

        A& operator = (A &a) { cout << "A:: = " << endl;}

        A(const A& a) { cout << "A::A(A&)" << endl; }
   private:
        //A(const A& a) { cout << "A::A(A&)" << endl; }
};

A func() {

    A a("str"); 

    return a;
}

A func(int) {

    return 10;
}

int main() {

    func();
    
    func(10);

    return 0;
}


