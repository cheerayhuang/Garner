#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100] = {0};
    char str2[100] = {0};

    int recursion[100][100] = {0};

    FILE *fin = fopen("20.in", "r");
    if (fin == NULL) {
        fprintf(stderr, "read file failed.\n");
        return -1;
    }

    fscanf(fin, "%s", str1);
    fscanf(fin, "%s", str2);

    int i = 0; 

    for (i = 1; i < strlen(str2); ++i) {
        recursion[0][i] = 0; 
    }
    for (i = 1; i < strlen(str1); ++i) {
        recursion[i][0] = 0;
    }

    int j = 0;
    for (i = 0; i < strlen(str1); ++i) {
        for(j = 0; j < strlen(str2); ++j) {

            if (str1[i] == str2[j]) {
                recursion[i+1][j+1] = recursion[i][j] + 1;
                continue;
            }

            recursion[i+1][j+1] = recursion[i][j+1] > recursion[i+1][j] ? recursion[i][j+1] : recursion[i+1][j];
        }
    }

    printf("%d\n", recursion[strlen(str1)][strlen(str2)]);

    fclose(fin);
    return 0;
}

