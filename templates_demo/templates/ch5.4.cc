/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: ch5.4.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 11-14-2016 17:17:00
 * @version $Revision$
 *
 **************************************************************************/


#include <deque>

using namespace std;

template <typename T,
    template <typename ELEM, typename = std::allocator<ELEM>> class CONT = deque>
class Stack {
private:
    CONT<T> elems;

public:
    void push(T const&);
    void pop();
    T top() const;
    bool empty() const {
        return elems.empty();
    }

    template <typename T2,
        template <typename ELEM2, typename = allocator<ELEM2>> class CONT2>

    Stack<T, CONT>& operator=(const Stack<T2, CONT2> &);
};

template <typename T, template<typename, typename> class CONT>
void Stack<T, CONT>::push(T const& e) {
    elems.push_back(e);
}

template <typename T, template<typename, typename> class CONT>
void Stack<T, CONT>::pop() {
    elems.pop_back();
}

template <typename T, template<typename, typename> class CONT>
T Stack<T, CONT>::top() const {
    return elems.back();
}

template <typename T, template<typename, typename> class CONT>
template <typename T2, template<typename, typename> class CONT2>
Stack<T, CONT>& Stack<T, CONT>::operator=(const Stack<T2, CONT2>& rhs) {
    auto tmp = Stack<T2, CONT2>(rhs);

    elems.clear();

    while(!tmp.empty()) {
        elems.push_back(tmp.top());
        tmp.pop();
    }

    return *this;
}

int main() {
    return 0;
}
