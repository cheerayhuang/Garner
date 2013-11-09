#include <stdio.h> 


int is_even(int x) {
    return (x & 1) == 0;
}


int main() {

    int input_data[] = {1, 2, 3, 6, 5, 11, 4, 9, 10, 8, 7};

    int i = 0; 
    int j = -1;
    for (; i < 11; ++i) {
        if (is_even(input_data[i]) == 0) {
            j++;
            int tmp = input_data[i];
            input_data[i] = input_data[j];
            input_data[j] = tmp;
        }
    }

    for (i = 0; i < 11; ++i) {
        printf("%d ", input_data[i]);
    }
    printf("\n");
    
    return 0;
}
