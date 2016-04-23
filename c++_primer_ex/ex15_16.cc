#include <iostream>
#include <string>

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
    }

private:
    size_t min_qty = 0;
    double discount = 0;
};

int main() {

    Quote q("book1", 10.0);

    BulkQuote b("book2", 11.1, 10, 0.3);

    Quote *p = &b;
    cout << p->NetPrice(10) << endl;
    p->Debug();

    const Quote &r = LimitQuote("book3", 12.5, 10, 0.4);
    cout << r.NetPrice(11) << endl;

    return 0;
}
