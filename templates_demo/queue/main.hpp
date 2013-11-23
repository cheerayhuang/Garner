#include <iostream> 

// pre-declare
template <typename T> class queue_item; 
template <typename T> class queue;  

template <typename type> 
std::ostream& operator<< (std::ostream& os, const queue<type>& q) {

    os << '<'; 
    queue_item<type> *h = q.head;  

    while (h->next != 0) {
        os << h->item << ','; 
        h = h->next;
    }
    os << h->item << '>';

    return os;
}


template <typename type> 
class queue {

    friend std::ostream& operator<< <type> (std::ostream &os, const queue<type>&);

public:
    queue(): head(0), tail(0) {}
    queue(const queue &q) : head(0), tail(0) { copy_element(q); }
    
    template <typename iter>
    queue(const iter& beg, const iter& end): head(0), tail(0) {

        destroy(); 
        copy_element(beg, end);
    }

    template <typename iter> 
    queue(iter *beg, iter *end): head(0), tail(0) {

        std::cout << "go here!" << std::endl; 

        destroy();
        copy_element(beg, end);
    }
    
    queue& operator =(const queue &q); 
    ~queue() { destroy(); }

    type &front() { return head->item;} 
    const type &front() const { return head->item;}

    void push(const type &);
    void pop();
    bool empty() const { return head == 0; }

private:

    queue_item<type> *head; 
    queue_item<type> *tail; 

    void destroy(); 
    void copy_element(const queue&);

    template <typename iter_ag> 
    void copy_element(iter_ag beg, iter_ag end) {

        destroy(); 

        *beg =5;
        iter_ag b = beg;

        // the iterator type should support "++" and "*" operator.
        for (; b != end; ++b) {
            push(*b);
        }
    }
};

template <typename type>
void queue<type>::push(const type& data) {

    queue_item<type> *new_node = new queue_item<type>(data);

    if (empty()) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node; 
        tail = tail->next;
    }
}

template <typename type> 
void queue<type>::pop() {
   
    if (!empty()) {
        queue_item<type>* tmp = head; 
        head = head->next; 

        delete tmp; 
    }
}

template <typename type> 
void queue<type>::destroy() {

    while (!empty()) {
        pop();
    }
}

template <typename type>
void queue<type>::copy_element(const queue& q) {

    destroy();
    queue_item<type>* h = q.head;
    
    while (h != 0) {
        push(h->item); 
        h = h->next;
    }
}

template <typename type>
queue<type>& queue<type>::operator =(const queue& q) {
    
    destroy();
    copy_element(q);
}

template <typename type> 
class queue_item {

    friend std::ostream& operator << <type> (std::ostream &os, const queue<type>&);
    friend class queue<type>;

private:

    queue_item(const type& t): item(t), next(0) {}
    type item;
    queue_item *next; 
};

