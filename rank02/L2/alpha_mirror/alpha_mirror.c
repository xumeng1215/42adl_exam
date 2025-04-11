#include <stdio.h>
#include<string.h>
void inverse(char *str);
int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);

    // Remove the newline character from the input string
    int len = strlen(str) - 1;
    if (str[len] == '\n')
        str[len] = '\0';
     inverse(str);
     printf("%s\n",str);
return 0;
}
void inverse(char *str)
{
    while(*str!='\0')
    {
        if( (*str>='a' && *str<='z') || (*str>='A' && *str<='Z') )
        {
            if(*str>='a' && *str<='z')
                *str= 'z' - (*str-'a');
            else
                *str= 'Z' - (*str-'A');
        }
        str++;
    }
}