#include <iostream>

using namespace std;

template <typename elemType> class ListItem;

template <typename elemType> class List {
public:
    List<elemType>();
    List(const List &);
    List& operator=(const List&);
    ~List();


    ListItem<elemType> *front, *end;

    void Insert(ListItem<elemType> *ptr, elemType value);

};

int main() {

    return 0;
}
