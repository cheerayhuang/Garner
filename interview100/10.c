#include <limits.h>
#include <stdio.h>

int main() {

    int inpute_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 34};
    int beg = 0; 
    int end = 12;
    int sum = 0;

    if (scanf("%d", &sum) != 1) {
        fprintf(stderr, "read inpute data failed.\n");
        return -1;
    }
    
    while (beg < end) {
       
        int tmp = inpute_data[beg] + inpute_data[end];
        if (tmp  == sum) {
            printf ("data[%d] + data[%d] = %d + %d = %d\n", 
                    beg, end, inpute_data[beg], inpute_data[end], sum);
            break;
        }

        if (tmp < sum) {
            beg++; 
        }

        if (tmp > sum) {
            end--;
        }
    }

    return 0;
}

