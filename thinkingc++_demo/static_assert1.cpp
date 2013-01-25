#define STATIC_ASSERT(x) \
    do { int a[(x) ? 1 : -1]; } while(0)


int main()
{
    STATIC_ASSERT(sizeof(int) <= sizeof(long)); 
    STATIC_ASSERT(sizeof(double) <= sizeof(int)); 
    
    typedef int i32[5]; 

    i32 k; 

    k[1];

    return 0; 
}

