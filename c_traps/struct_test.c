#include <stdio.h>


struct A {


    char i : 7; 

    char j : 6; 

    int k : 18;
};


int main()
{

    printf("%u", sizeof(struct A)); 

    
    return 0; 
}

