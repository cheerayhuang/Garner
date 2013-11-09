#include <limits.h>
#include <stdio.h>

int main() {

    int input_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 34};
    int beg = 0; 
    int end = 12;
    int sum = 0;

    if (scanf("%d", &sum) != 1) {
        fprintf(stderr, "read input data failed.\n");
        return -1;
    }
    
    while (beg < end) {
       
        int tmp = input_data[beg] + input_data[end];
        if (tmp  == sum) {
            printf ("data[%d] + data[%d] = %d + %d = %d\n", 
                    beg, end, input_data[beg], input_data[end], sum);
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

