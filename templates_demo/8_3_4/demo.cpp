#include <iostream> 

template <typename T, T N> class C; 

class Base {

    public:
        static int i; 
} base ;

int Base :: i = 0; 

int main() 
{
    C<int *, &Base::i> *demo ; 

    return 0; 

}
