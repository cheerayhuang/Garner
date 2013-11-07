#include <stdio.h> 
#include <string.h>


int reverse(char *str, size_t beg, size_t end)
{
    if (str == NULL) {
        return -1;
    }

    while (beg < end) {
        char tmp = str[beg]; 
        str[beg++] = str[end]; 
        str[end--] = tmp;
    }
    return 0;
}

int main()
{
    FILE *fin = NULL;
    char str[100];

    fin = fopen("7.in", "r");
    if (fin == NULL) {
        fprintf(stderr, "open 7.in failed.\n");
        return -1;
    }

    if (fgets(str, 100, fin) == NULL) {
        fprintf(stderr, "read file failed.\n");
        return -1;
    }
    str[strlen(str)-1] = '\0';

    if (reverse(str, 0, strlen(str)-1) != 0) {
        fprintf(stderr, "reverse string failed.\n");
        return -1;
    }

    char *end= NULL;
    char *curr = str;
    while((end=strchr(curr, ' ')) != NULL) {
        if (*curr == ' ') {
            curr++; 
            continue;
        }

        if (reverse(str, curr-str, end-str-1) != 0) {
            fprintf(stderr, "reverse string failed.\n");
        }

        curr = end + 1;
    }
    fclose(fin);

    printf("revers string = %s\n", str);

    return 0;
}

