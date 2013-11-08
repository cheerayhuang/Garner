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
    char str[100] = {0};
    int offset = 0;

    scanf("%s %d", str, &offset);

    reverse(str, 0, offset-1);
    reverse(str, offset, strlen(str)-1);
    reverse(str, 0, strlen(str)-1);

    printf("%s\n", str);

    return 0;
}
