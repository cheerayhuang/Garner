#include <iostream>

using namespace std;

class Base {

};

class DerivedBasePublic : public Base {
};


class DerivedBaseProtected: protected Base {
};

class DerivedBasePrivate: private Base {
};

class DAgainPublic : public  DerivedBasePublic {
    void Test() {
        DerivedBasePublic d;
        Base *b = &d;
    }
};

class DAgainProtected: public DerivedBaseProtected {
    void Test() {
        DerivedBaseProtected d;
        Base &b = d;
    }

};

class DAgainPrivate: public DerivedBasePrivate {
    void Test() {
        DerivedBasePrivate d;
        //Base *b = &d;
    }
};

int main() {

    DerivedBasePublic d1;
    Base *p = &d1;

    DerivedBaseProtected d2;
    //p = &d2;

    DerivedBasePrivate d3;
    //p = &d3;


    DAgainPublic d4;
    p = &d4;

    DAgainProtected d5;
    //p = &d5;

    DAgainPrivate d6;
    //p = &d6;



    return 0;
}
