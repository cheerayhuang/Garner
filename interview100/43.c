#include <stdio.h> 
#include <string.h>

int main()
{
    int num_of_sum[2][37] = {0};

    int i = 0; 
    for (i = 1; i <= 6; ++i) {
        num_of_sum[0][i] = 1; 
    }

    int curr = 1;
    for (i = 2; i <= 6; ++i) {
        
        int j = i; 
        while(j <= 6*i) {
            if (j <= 7) {
                num_of_sum[curr][j] = num_of_sum[curr][j-1] + num_of_sum[1-curr][j-1];
            }
            else {
                num_of_sum[curr][j] = num_of_sum[curr][j-1] - num_of_sum[1-curr][j-7] + num_of_sum[1-curr][j-1];
            }

            if (j == 6*i) {
                printf("%d\n", num_of_sum[curr][j]);
            }
            ++j;
        }

        curr = 1 - curr;
        memset(num_of_sum[curr], 0, sizeof(num_of_sum[curr]));
    }

    double total = 1.0;
    for (i = 0; i < 6; ++i) {
        total *= 6;
    }

    for (i = 0; i < 6; ++i) {
        num_of_sum[1-curr][i] = 0;
    }

    int sum = 0;
    scanf("%d", &sum);

    printf("%d\n%f\n", num_of_sum[1-curr][sum], num_of_sum[1-curr][sum] / total);
    
    return 0;
}

