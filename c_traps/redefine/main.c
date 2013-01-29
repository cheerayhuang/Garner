#include <stdio.h> 

extern short n; 

int main() 

{
    n = 100000000; 
    
    printf("%d\n", n); 

    return 0; 
}
