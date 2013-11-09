#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

char *delete_(const char *str, const char *deleted_char) {

    if (str == NULL || deleted_char == NULL) {
        return NULL;
    }

    char *result = (char*)malloc(strlen(str)+1);
    if (result == NULL) {
        return NULL;
    }

    uint8_t hash[26];
    memset(hash, 0, sizeof(hash));
    
    int i; 
    for (i = 0; i < strlen(deleted_char); ++i) {
        int key = deleted_char[i] - 'A';
        if (key > 25) {
            key = deleted_char[i] - 'a';
        }
        hash[key] = 1;
    }

    int j = 0;
    for (i = 0; i < strlen(str); ++i) {
       int key = str[i] - 'A'; 
       if (key > 25) {
           key = str[i] - 'a';
       }

       if (hash[key] == 0) {
           result[j++] = str[i];
       }
    }

    result[j] = '\0';

    return result;
}

int main()
{
    char str[] = "They are students.";
    char deleted_char[] = "aeiou";

    char *result = delete_(str, deleted_char);
    if (result == NULL) {
        fprintf(stderr, "delete failed.\n");
        return -1;
    }
    printf("%s\n", result);

    return 0;
}
