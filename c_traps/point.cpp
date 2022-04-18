#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

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

    int(*p)[2]=new int[3][2];

    p = a;

    printf("\n%d\n", *(*(p+1)+1));
    printf("\n%d\n", *(*(p)+1+1));
    //printf("\n%d\n", *a);

    vector<int> result(1000000000, 1);

    cout << result.size() << endl;

    return 0;
}
