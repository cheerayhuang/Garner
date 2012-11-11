#include <stdio.h> 
#include <limits.h> 

int main() 
{
    
    int *p; 
    int (*parr) [5]; 
    int c[5][5]; 

    p = c[0]; 

    parr = c; 

    printf("%d\n", INT_MAX); 
    printf("%ld\n", LONG_MAX); 

    unsigned int a = 4100000000; 
    unsigned int b = 1200000000; 

    printf("%u\n", a+b); 

    return 0; 
}

