#include <iostream> 
#include <vector> 
#include <memory> 

using namespace std; 

template <typename T, template <typename, typename = allocator<T> > class Seq>
class Container {

    Seq<T> seq; 

public: 

    void push_back(const T& t) { seq.push_back(t); } 

    typedef typename Seq<T>::iterator iterator; 

    iterator begin() { return seq.begin(); } 
    iterator end() { return seq.end(); } 

};

int main() 
{

    Container<int, vector> vContainer; 

    vContainer.push_back(1); 
    vContainer.push_back(2); 


    for(Container<int, vector>::iterator p = vContainer.begin(); 
            p != vContainer.end(); ++p)  
    {
        cout << *p << endl; 
    
    }

    return 0; 
}


