#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char **arr) {

    *arr = (char*)realloc(*arr, 20);
    strcat(*arr, " world");
}

void func2(int(*arr)[2]) {
    for(int i = 0; i <3; ++i)
        for(int j = 0; j < 2; ++j) {
            printf("%d, ", *(*(arr+i)+j));
        }

}

void func3() {

}

int main() {
    char ** arr = (char**) malloc (sizeof(char*) * 10);

    arr[0] = (char*)malloc(10);

    strcpy(arr[0], "hello");

    printf("%s\n", arr[0]);

    func(arr);

    printf("%s\n", *arr);

    free(arr[0]);

    free(arr);

    int a[3][2] = {1,2,3,4,5};

    func2(a);

    return 0;
}
