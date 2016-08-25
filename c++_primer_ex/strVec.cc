/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: strVec.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 04-17-2016 23:42:04
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

class StrVec {

public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(size_t size, const string &str) {
        elements = alloc.allocate(size*2);
        cap = elements + size*2;
        for (first_free = elements; first_free-elements != size; first_free++)
            alloc.construct(first_free, str);
    }

    StrVec(const StrVec&);
    StrVec(StrVec &&s) noexcept: elements(s.elements), first_free(s.first_free), cap(s.cap){
        s.elements = s.first_free = s.cap;
    }
    StrVec &operator=(const StrVec&);
    StrVec &operator=(StrVec&& rhs) noexcept {
        if (this != &rhs) {
            Free();
            elements = rhs.elements;
            first_free = rhs.first_free;
            cap = rhs.cap;
            rhs.elements = rhs.first_free = rhs.cap = nullptr;
        }

        return *this;
    }
    ~StrVec();

    template<typename... ARGS>
    void emplace_back(ARGS&&... args);
    void push_back(const string&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string* begin() const { return elements; }
    string* end() const { return first_free; }



private:
    static allocator<string> alloc;

    void CheckAlloc() {
        if (size() == capacity()) Reallocate();
    }

    void Free();
    void Reallocate();

    string* elements;
    string* first_free;
    string* cap;
};

allocator<string> StrVec::alloc = allocator<string>();

StrVec::StrVec(const StrVec &s) {
    auto p = alloc.allocate(s.capacity());
    auto p_end = uninitialized_copy(s.begin(), s.end(), p);

    Free();

    elements = p;
    first_free = p_end;
    cap = elements + size()*2;
}

StrVec& StrVec::operator=(const StrVec &s) {
    auto p = alloc.allocate(s.capacity());
    auto p_end = uninitialized_copy(s.begin(), s.end(), p);

    Free();

    elements = p;
    first_free = p_end;
    cap = elements + size()*2;

    return *this;
}

void StrVec::push_back(const string& s) {
    CheckAlloc();
    alloc.construct(first_free++, s);
}

template<typename... ARGS>
void StrVec::emplace_back(ARGS&&...args) {
    CheckAlloc();
    alloc.construct(first_free++, std::forward<ARGS>(args)...);
}

void StrVec::Free() {
    /*for (auto p = elements; p != first_free; ++p)
        alloc.destroy(p);
    alloc.deallocate(elements, capacity());
    */

    for_each(elements, first_free, [&](decltype(elements[0]) p)->void { alloc.destroy(&p); });
    alloc.deallocate(elements, capacity());
}

void StrVec::Reallocate() {
    auto new_elements = alloc.allocate(capacity() * 2);
    //auto new_first_free = uninitialized_copy(begin(), end(), new_elements);

    auto n = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), new_elements);

    Free();

    elements = new_elements;
    first_free = n;
    cap = elements + size()*2;
}

StrVec::~StrVec() {
    Free();
}

int main() {
    StrVec s(1, string("hello"));
    s.push_back("world!");
    s.push_back("world!");

    for (auto i : s) {
        cout << i << endl;
    }

    cout << s.capacity() << endl;
    s.emplace_back(10, 'c');

    cout << *(s.end()-1) << endl;
    cout << s.capacity() << endl;
    cout << s.size() << endl;

    s.push_back("world!");
    cout << s.capacity() << endl;
    cout << s.size() << endl;

    return 0;
}
