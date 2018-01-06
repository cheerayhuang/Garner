/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: map.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 11-07-2014 18:08:05
 * @version $Revision$
 *
 **************************************************************************/
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class A{
    private:
        int i;
    public:
        A() {}
        A(int k, int) { i = k; }
        bool operator < (const A& a) const {
            return i < a.i;
        }

        bool operator == (const A& a) const {
            return i == a.i;
        }

        friend ostream & operator << (ostream &os, const A& a) {
            os << "this is a";
            return os;
        }

        int GetI() {
            return i;
        }
};

class B {

    public:
        /*
        void func() {
            B * k = this;
            cout << "non const " << endl;
        }*/

        void func() const {
            cout << "const " << endl;
        }
};

int main() {

    vector<pair<int, int>> v;
    map<int ,int> m (v.begin() , v.end());
    set<int> s {0};
    m[0] = -1;
    auto res_map = find_if(m.begin(), m.end(),
                           [](pair<int, int>p) {
                               if (p.first == 0 && p.second == -1) {
                                   cout << "hello world";
                                   return true;
                               }

                               return false;
                           });
    auto res_set = find(s.begin(), s.end(), 0);

    if (res_map == m.end()) {
        cout << "find nothing in map." << endl;
    }

    if (res_set == s.end()) {
        cout << "find nothing in set." << endl;
    }

    map<A, int> m_classA;
    m_classA.emplace(A(5, 10), 10);
    m.emplace(-1, 2);

    A a(5,10);
    A a2(6, 11);

    m_classA.emplace_hint(m_classA.begin(), make_pair<A, int>(A(6, 11), 11));
    m_classA.insert(m_classA.begin(), make_pair<A, int>(A(7,12), 12));

    cout << m_classA[a] << endl;
    cout << m_classA[a2] << endl;
    cout << m_classA[A(7,12)] << endl;

    vector<A> vec_classA;

    auto it = vec_classA.emplace(vec_classA.begin(), 5, 10);
    vec_classA.emplace(it, 4, 10);

    cout << vec_classA.begin()->GetI() << ' ' << (vec_classA.begin()+1)->GetI() << endl;

    /*unordered_map<A, int> uord_m;
    uord_m.emplace(A(5,10), 10);
    */



    map<int, A> null_map;

    cout << null_map[5] << endl;

    const map<int, int> c_map {{1,1}, {1,2}};

    for (auto m : c_map) {
        cout << m.first << ' ' << m.second << endl;
    }

    c_map.at(1) ;

    const B b;
    //b.func(); // compile error if func is not a const memeber function.

    b.func();

    return 0;
}
