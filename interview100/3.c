#include <stdio.h>
#include <limits.h>

int compute_max(FILE *fin, int *sum)
{
    int i; 
    
    int max = INT_MIN;

    if (sum == NULL) {
        return -1;
    }

    while (fscanf(fin, "%d", &i) != EOF) {
        *sum += i; 
        if (*sum < 0) {
            *sum = 0;          
        }

        if (*sum > max) {
            max = *sum;
        }
    }

    *sum = max;

    if (ferror(fin) != 0) {
        return -1;
    }

    return 0;
}

int main() 
{

    FILE *fin = fopen("3.in", "r");
    if (fin == NULL) {
        perror("open file failed.\n");
        return -1;
    }
    
    int sum = 0;
    
    if (compute_max(fin, &sum) != 0) {
        perror("compute operation failed.\n");
        return -1;
    }

    printf("max sum = %d\n", sum);
    return 0;
}

