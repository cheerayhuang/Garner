#include <stdio.h> 
#include <stdint.h>
#include <string.h>

int main()
{
    uint8_t hash[26]; 

    memset(hash, 0, sizeof(hash));
    
    char str[100];
    scanf("%s", str);

    int len = strlen(str); 
    int i = 0; 

    for (i = 0; i < len; ++i) {

        if (str[i] >= 'A' && str[i] <= 'Z') {
            hash[str[i]-'A']++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            hash[str[i]-'a']++;
        }
    }

    for (i = 0; i < 26; ++i) {
        if (hash[i] == 1) {
            printf ("%c\n", i+'a');
            break;
        }
    }

    return 0;
}

