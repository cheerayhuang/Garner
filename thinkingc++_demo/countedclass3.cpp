#include <iostream> 

using namespace std;

template <typename T> 
class Counted {

    static int count; 

public :
   Counted() { ++count; }
   Counted(const Counted&) { ++count; } 
   ~Counted() { -- count; } 

   static int getCount() { return count;} 
};

template<typename T> 
int Counted<T>::count = 0; 

class CountedClass : public Counted<CountedClass> {} ;
class CountedClass2 : public Counted<CountedClass2>{} ;

int main()
{
    CountedClass a; 
    cout << CountedClass :: getCount() << endl; 

    CountedClass b; 
    cout << CountedClass :: getCount() << endl; 

    CountedClass2 c; 
    cout << CountedClass2 :: getCount() << endl; 

    return 0; 
}

