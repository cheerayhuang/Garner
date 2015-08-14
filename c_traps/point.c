#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char **arr) {

    *arr = (char*)realloc(*arr, 20);
    strcat(*arr, " world");
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

    return 0;
}
