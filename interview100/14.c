#include <stdio.h> 
#include <stdint.h>


int main() {
    
    int n = 0; 
    int m = 0;
    if (scanf("%d %d", &n, &m) != 2) {
        fprintf(stderr, "read data failed.\n");
        return -1;
    }
    
    int i = 2;

    int s = 0;
    for (; i <= n; ++i) {
        s = (s+m) % i; 
    }

    printf("%d\n", s);
    return 0;
}

