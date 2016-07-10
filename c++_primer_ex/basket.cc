/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: basket.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 07-10-2016 17:05:17
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <string>
#include <memory>
#include <set>

using namespace std;

class Quote {

public:
    Quote(const string& isbn="none", double price=0.0f):
        isbn(isbn), price(price) {
    }

    Quote(const Quote& q) {
        isbn = q.isbn;
        price = q.price;
    }

    Quote(Quote&& q) {
        isbn = q.isbn;
        price = q.price;
    }

    Quote& operator=(const Quote& q) {
        isbn = q.isbn;
        price = q.price;

        return *this;
    }

    Quote& operator=(Quote&& q) {
        *this = q;

        return *this;
    }

    ~Quote() {
        cout << "~Quote()" << endl;
    }

public:
    string Isbn() { return isbn; }
    double Price() { return price; }


private:
    string isbn;
    double price;

    friend ostream& operator<<(ostream& os, const Quote& q) {
        os << q.isbn << ' ' << q.price;
        return os;
    }

};

class Basket {

public:
    Basket() = default;
    ~Basket() = default;

public:
    void AddItem(const Quote& q) {
        items.insert(shared_ptr<Quote>(new Quote(q)));

    }

    void AddItem(Quote&& q) {
        items.insert(shared_ptr<Quote>(new Quote(std::move(q))));
    }


private:

    static bool compare(const shared_ptr<Quote> &lhs,
                        const shared_ptr<Quote> &rhs) {

        return lhs->Isbn() < rhs->Isbn();
    }

    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};

    friend ostream& operator<<(ostream& os, const Basket& b) {
        auto sum = 0.0f;
        for(auto iter = b.items.begin(); iter != b.items.end(); iter = b.items.upper_bound(*iter)) {
            os << **iter << endl;
            sum += (*iter)->Price();
        }
        os << "sum price: " << sum;

        return os;
    }
};

int main() {
    Quote q1("book1", 5.5f);
    Quote q2("book2", 6.5f);
    Quote q3(std::move(q2));

    Quote q4;
    {
        Quote q4_1("book3", 7.5f);
        q4 = std::move(q4_1);
    }

    Basket basket;

    basket.AddItem(q1);
    basket.AddItem(std::move(q2));
    basket.AddItem(std::move(q4));
    basket.AddItem(q3);

    cout << basket << endl;

    return 0;
}
