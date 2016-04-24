#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>

using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price):
        book_no_(book), price_(sales_price) {}

    const string& book_no() const {
        return book_no_;
    }

    virtual double NetPrice(std::size_t n) const {
        return n * price_;
    }

    virtual void Debug() const {
        cout << "book_no_: " << book_no_ << endl;
        cout << "price_: " << price_ << endl;
    }

    virtual shared_ptr<Quote> Clone() const & {
        //return make_shared<Quote>(*this);
        return shared_ptr<Quote>(new Quote(*this));
    }

    virtual shared_ptr<Quote> Clone() const && {
        return shared_ptr<Quote>(new Quote(std::move(*this)));
    }

    int test = 0;

private:
    string book_no_;

protected:
    double price_ = 0.0;
};

class DiscQuote : public Quote {
public:
    using Quote::Quote;

    double NetPrice(std::size_t n) const = 0;

    void Debug() const = 0;

    shared_ptr<Quote> Clone() const & = 0;

};

class BulkQuote : public DiscQuote {
public:
    BulkQuote() = default;
    BulkQuote(const string &book, double sales_price, std::size_t qty, double discount):
        DiscQuote(book, sales_price), min_qty(qty), discount(discount) {
    }

    double NetPrice(std::size_t n) const {
        if (n >= min_qty) {
            return n * discount * price_;
        }
        else {
            return n * price_;
        }
    }

    void Debug() const {
        Quote::Debug();
        cout << "min_qty: " << min_qty << endl;
        cout << "discount: " << discount << endl;
        cout << "-----" << endl;
    }

    shared_ptr<Quote> Clone() const &{
        return shared_ptr<Quote>(new BulkQuote(*this));
    }

    shared_ptr<Quote> Clone() const && {
        return shared_ptr<Quote>(new BulkQuote(std::move(*this)));
    }

private:
    size_t min_qty = 0;
    double discount = 0;
};

class LimitQuote : public DiscQuote {
public:
    LimitQuote() = default;
    LimitQuote(const string &book, double sales_price, std::size_t qty, double discount):
        DiscQuote(book, sales_price), min_qty(qty), discount(discount) {
        }

    double NetPrice(std::size_t n) const {
        if (n <= min_qty) {
            return n * discount * price_;
        }
        else {
            return min_qty * discount * price_ + (n-min_qty) * price_;
        }
    }

    void Debug() const {
        this->Quote::Debug();
        cout << "min_qty: " << min_qty << endl;
        cout << "discount: " << discount << endl;
        cout << "-----" << endl;
    }

    shared_ptr<Quote> Clone() const &{
        return shared_ptr<Quote>(new LimitQuote(*this));
    }

    shared_ptr<Quote> Clone() const && {
        return shared_ptr<Quote>(new LimitQuote(std::move(*this)));
    }

private:
    size_t min_qty = 0;
    double discount = 0;
};

class Basket {
public:
    Basket() = default;

    void AddStuff(const Quote & q) {
        auto bak = q.Clone();

        stuffs.insert(bak);
        //bak->Debug();
        bak->test = 10243;
    }

    void AddStuff(Quote && q) {
        cout << "right ref" << endl;
        auto bak = q.Clone();
        stuffs.insert(std::move(bak));
    }

    void TotalRecepit() {
        auto sum = 0.0d;
        for (auto iter = stuffs.cbegin(); iter != stuffs.cend(); iter = stuffs.upper_bound(*iter)) {
            cout << (*iter)->book_no() << " " << stuffs.count(*iter) << " " << (*iter)->NetPrice(stuffs.count(*iter)) << endl;
            sum = sum + (*iter)->NetPrice(stuffs.count(*iter));
        }

        cout << "Basket sum: " << sum << endl;
    }

public:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
        return lhs->book_no() < rhs->book_no();
    }
private:
    multiset<shared_ptr<Quote>, decltype(compare)*> stuffs{compare};
};

int main() {

    Quote q("book1", 10.0);
    BulkQuote b("book2", 11.1, 10, 0.3);
    Quote *p = &b;
    const Quote &r = LimitQuote("book3", 12.5, 10, 0.4);

    Basket basket;
    basket.AddStuff(q);
    basket.AddStuff(b);
    basket.AddStuff(*p);
    basket.AddStuff(r);
    basket.AddStuff(LimitQuote("book4", 20, 1, 0.4));

    basket.TotalRecepit();

    return 0;
}
