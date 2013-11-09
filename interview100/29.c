#include <stdio.h> 


int is_even(int x) {
    return (x & 1) == 0;
}


int main() {

    int inpute_data[] = {1, 2, 3, 6, 5, 11, 4, 9, 10, 8, 7};

    int i = 0; 
    int j = -1;
    for (; i < 11; ++i) {
        if (is_even(inpute_data[i]) == 0) {
            j++;
            int tmp = inpute_data[i];
            inpute_data[i] = inpute_data[j];
            inpute_data[j] = tmp;
        }
    }

    for (i = 0; i < 11; ++i) {
        printf("%d ", inpute_data[i]);
    }
    printf("\n");
    
    return 0;
}
