#include <stdio.h>

void Print(int (*p)[2], int x, int y) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d, ", *(*(p+i)+j));
        }
    }
}

int main() {
    int arr[2][2] = {1,2,3,4};

    Print(arr, 2,2);
    return 0;
}
