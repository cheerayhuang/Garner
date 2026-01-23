#include <iostream>

template <typename T>
class A {
public:
    int operator *(A<T> a) {
        return i * a.i;
    }

    int i;
};


namespace X {

class C {

};
}



template <typename T>
void f(A<T>, double) {std::cout << "f(double)" << std::endl; }

namespace X  {
    void g(X::C, double) {std::cout << "g(double)" << std::endl;}

    //void g(X::C, int);
}


class E;

template <typename T>
class B { 
public:
    A<T> a1, a2;

    //void func(A<T> a1, A<T> a2) {
    void func() {
        // 待决名与非待决名的概念只用于模版中

        // 这里调用了 operator*(a1, a2)
        // 在调用处使用了ADL查找
        // 根据ADL的定义，只有在 function call expression 里才会发生 ADL！
        std::cout << a1*a2 << std::endl;
        // 由于有a1参数的存在，这里的f<T>待决名查找会使用 ADL;
        // 这里会最终打印 f(int)
        f<T>(a1, 1);

        //尽管 f<T> 在这里也是待决名，会延迟到模版实例化时进行名字查找，
        //可参数为基本类型int，所以不会进行ADL查找，因此还是只能找到上面的 f(double)
        //f<T>(1);

        // 非待决名的函数调用
        g(X::C(), 1);
        //h(A<int>(), 1);

        // 待决名的函数调用，由于实例化已经确定，此时是可以根据实例化来进行ADL的
        // 查找点是从实例化点开始。。所以可以找到两个int函数
        // 猜测:只有模版实例化，可以通过 ADL找到所有文件域的函数
        h(a1, 1);
        h(a2, 1.2);
        h(A<T>(), 1);
    }
};

void h(A<int>, double) {std::cout << "h(double)" << std::endl;}

class E {
    public:
        friend void j(E* e) {
            std::cout << "E::j" << std::endl; 
        }

        class F;
};

//template <typename T>
int j(E* e, float) {
    std::cout << "E::j(float)" << std::endl;
    return 0;
}

//template <typename T = int>
class D {
    public:
        void func() {
            // 这里不是模版定义内部，所以实际上不存在所谓的非待决名
            X::C c1;
            // 调用的是g(double), 通过ADL找到 X::g
            g(c1, 1);

            //error，不存在待决名查找推迟，即便是通过ADL，
            //由于E 所在的名字空间也没有g，因此报错
            //g(E());

            j(new E());
            // 尽管有 ADL，对于非待决名，还是找不到后面的 j(E* ,int)
            //j<int>(new E(), 1);

            // 如果把后面的j函数改为模版，类D改为模版，在这里让其成为一个待决名
            // 则可以找到后面的 j(E*, int)
            //j<T>(new E(), 1);

            // 如果改为普通的调用，不在模版内，不存在待决名，
            // 即便有 ADL，还是找不到后面的j(E* , int), ADL的file scope查找依然查找的是 before 之前的。 
            // !!!原因是：模版待决名的查找，伴随着相关模版的实例化
            // 只要是与j相关的模版都会实例化，因此无论放置位置在哪里，都能找到
            j(new E(), 1);

            //E::F* pf;
            //k(pf, 1);
        }

};

class E::F {
    public:
        friend int k(F*, double) {std::cout << "k(double)" << std::endl; return .0;}
        friend void k(F*, int) {std::cout << "k(int)" << std::endl;}
};

//template <typename T>
int j(E* e, int) {
    std::cout << "E::j(int)" << std::endl;
    return 0;
}

template <typename T>
void f(A<T>, int) {std::cout << "f(int)" << std::endl; }

namespace X {

    void g(X::C, int) {std::cout << "g(int)" << std::endl;}
    //void g(E) {std::cout << "g(E) by ADL E" << std::endl;}
}

int main() {
    A<int> a1, a2;

    a1.i = 5;
    a2.i = 6;

    std::cout << a1*a2 << std::endl;

    B<int> b1;
    //b1.func(a1, a2);
    b1.func();

    D d1;
    d1.func();

    return 0;
}

void h(A<int>, int) {std::cout << "h(int)" << std::endl;}
