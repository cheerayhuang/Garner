#include <stdio.h>

int is_one(int num, int bit_index) {

    num = num >> bit_index;

    return (num & 1) == 1;
}

int find_bit_is_1(int xor_result, int *bit_index) {

    while (*bit_index < 32) {
        xor_result >>= *bit_index;
        if ((xor_result & 1) == 1) {
            break;
        }
    }
    return 0;
}

int main()
{
    int input_data[] = {1, 1, 2, 2, 3, 3, 100,101};
    int i = 0; 

    int xor_result = 0;
    for (; i < 8; ++i) {
        xor_result ^= input_data[i];
    }

    int bit_index = 0;
    find_bit_is_1(xor_result, &bit_index);

    int diff_num1 = 0; 
    int diff_num2 = 0;
    for (i = 0; i < 8; ++i) {

        if (is_one(input_data[i], bit_index)) {
            diff_num1 ^= input_data[i];
        }
        else {
            diff_num2 ^= input_data[i];
        }
    }

    printf("%d %d\n", diff_num1, diff_num2);

    return 0;
}
