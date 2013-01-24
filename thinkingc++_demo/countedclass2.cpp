#include <iostream> 

using namespace std;

class Counted {

    static int count; 

public :
   Counted() { ++count; }
   Counted(const Counted&) { ++count; } 
   ~Counted() { -- count; } 

   static int getCount() { return count;} 
};

int Counted::count = 0; 

class CountedClass : public Counted {} ;
class CountedClass2 : public Counted{} ;

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

