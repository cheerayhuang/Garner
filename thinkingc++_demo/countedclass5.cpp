/*
 this demo, will show that template-template parameters can terminate the recursive definition. 
*/

#include <iostream> 


using namespace std;

template <typename T> 
class Counted {

    static int count; 

public :
/*   Counted() { ++count; }
   Counted(const Counted&) { ++count; } 
   ~Counted() { -- count; } 
*/
   static int getCount() { return count;} 
   static int IncCount() { ++count; } 
};

template<typename T> 
int Counted<T>::count = 0; 

template< template<typename> class T> 
class CountedClass : public T<CountedClass<T> >  {

    public:

    CountedClass() { T<CountedClass<T> > :: IncCount();} 

    /*static int getCount() 
    {
        return Counted<CountedClass>::getCount() ;
    }
    */
};

template< template<typename> class T> 
class CountedClass2 : public T<CountedClass2<T> > {
    
public:

    CountedClass2() { T<CountedClass2<T> > ::  IncCount(); }


};


int main()
{
    CountedClass<Counted> a; 
    cout << CountedClass<Counted> :: getCount() << endl; 

    CountedClass<Counted> b; 
    cout << CountedClass<Counted> :: getCount() << endl; 

    CountedClass2<Counted> c; 
    cout << CountedClass2<Counted> :: getCount() << endl; 

    return 0; 
}

