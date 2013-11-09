#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    int i = 1; 
    int j = 2; 

    int sum = i + j;

    while (i <=  (n+1)/2) {
        
        if (sum > n) {
            sum -= i;
            i++;
        }
        else if (sum < n) {
            j++;
            sum += j;
        }
        else {
            printf("%d-->%d\n", i, j);
            sum -= i;
            i++;
        }
    }
    return 0;
}
