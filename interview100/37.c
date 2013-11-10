#include <stdio.h> 

int min(int a, int b, int c) {

    int m = a; 

    if (b < m) {
        m = b;
    }

    if (c < m) {
        m = c;
    }

    return m;
}

int main(void) {

    int ugly_num[10000] = {0}; 
    int curr_num = 0;
    int n = 0; 

    scanf("%d", &n); 

    int j = 0;
    int t2 = 0;
    int t3 = 0; 
    int t5 = 0;
    ugly_num[0] = 1;

    while (curr_num < n) {

        curr_num = min(ugly_num[t2]*2, ugly_num[t3]*3, ugly_num[t5]*5);
        ugly_num[++j] = curr_num;

        while (ugly_num[t2]*2 <= curr_num) {
            t2++;
        }

        while (ugly_num[t3]*3 <= curr_num) {
            t3++;
        }

        while (ugly_num[t5]*5 <= curr_num) {
            t5++;
        }
    }

    int i = 0; 
    for(; i < j; ++i) {
        printf("%d ", ugly_num[i]);
    }

    printf("\n");

    return 0;
}

