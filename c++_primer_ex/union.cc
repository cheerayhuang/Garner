/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: union.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 06-15-2021 11:39:16
 * @version $Revision$
 *
 **************************************************************************/
#include<iostream>
#include <vector>

using namespace std;
//相同的内存地址
//


struct Pointer1 {
    const char *a;
    const char *b;

};

struct Pointer2 {
    int *i;
};

union myun
{
    struct { int x; int y; int z; }u;
    int k;

    Pointer1 p1;
    Pointer2 p2;
}a;

class A {
    public:

        int i = 0;
        auto func() const {
            cout << "hello world" << endl;
            return A();
        }

        void func() {
            cout << "hello chengdu" << endl;
        }

//        virtual void func_v() final {};
};

/*
class B : private A {
    public:
        void func_v() {
        }
};*/

int main()
{
    cout << sizeof(a) << endl;
    cout << sizeof(int*) << endl;
    a.u.x =4;
    a.u.y =5;
    a.u.z =6;
    a.k = 0; //覆盖掉第一个int空间值
    printf("%d %d %d %d\n",a.u.x,a.u.y,a.u.z,a.k);
    system("pause");

    const A a;
    a.func();

    A b;
    b.func();

    A * const c = new A();

    c->func();

    vector<int> v{10, 0};

    if (auto beg = v.cbegin(); beg != v.cend()) {
        cout << "hello beijing" << endl;
    }

    A d{5};
    d.func();


    int i = 0;
    (void) std::initializer_list<int>{([] {
std::cout << "hello list"<< std::endl;
}(), i)};

    (void) std::vector<int>{};

    cout <<(5,6) << endl;

    int *ptr_arr = new int[1];
    ptr_arr[0] = 1024;
    cout << *(ptr_arr) << endl;

    delete [] ptr_arr;

    return 0;
}

