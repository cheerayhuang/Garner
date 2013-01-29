#include <stdio.h> 
#include <string.h> 

int main() 
{
    char s[] = "123456789"; 
    char d[] = "1234"; 

    strcpy(s, d); 

    printf("s=%s, d=%s\n", s, d); 

    return 0; 
}

