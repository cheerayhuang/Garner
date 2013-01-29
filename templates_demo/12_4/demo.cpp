template <typename T, typename K, int N = 10> 
class A {
};

template <typename T> 
class A<T, int, 5> { 
}; 

template <typename KKKK5> 
class A<int , KKKK5, 5> {
};


template <int K> 
class A<int, double, K> {
};

int main() 
{
    return 0; 
}
