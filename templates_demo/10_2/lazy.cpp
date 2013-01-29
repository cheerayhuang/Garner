template < typename T> 
class Safe {
};


template <int N> 
class Danger {

    public: 
        typedef char Block[N]; 
        char Block2[N];
};

template <typename T, int N> 
class Tricky { 
    public : 

        virtual ~Tricky() 
        {

        }

        void no_body_here(Safe<T> = 3) ; 

        void inclass() 
        {
            Danger<N> no_boom_yet; 
        }

        // here, no errors in g++, since when "Tricky" instantiation happends , g++ just make declareation instantiation, don't make definition instantiation. so the declareation of "unsafe" can give an error. 

        void error() { Danger< -1> boom; } 
        void unsafe(T (*p)[0]); 

        T operator ->(); 
        //virtual Safe<T> suspect(); 
        
        struct Nested 
        {
            Danger<N> pfew; 
        }; 

        union  NestedU{ 
            int align; 
            Safe<T> anonymous; 
            Danger<N> boom; 

        };
};


class A {

    public: 

        void func() ; 
};

int main() 
{
    Tricky < int, -1> ok; 

    A a; 

    return 0; 
}


