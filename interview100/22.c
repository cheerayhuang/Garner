#include <stdio.h> 

int main() 
{
    int m = 0; 

    scanf("%d", &m);
    
    int sum = 0;
    while(m) {
        sum++;
        m &= m-1;
    }

    printf("%d\n", sum);

    return 0;
}
