#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
int find(char* str, char* sub)
{
    while(*sub)
    {
        if(*str++ != *sub++)
            return 0;

    }
    return 1;
}
char* substring(char* str, char* sub)
{
    if(!(*sub))
    {
        return str;
    }
    else
    {
        while(*str)
        {
            if(find(str, sub))
                return str;
            str++;
        }

        return NULL;
    }
}
int main()
{
    char str[100], sub[100];
    printf("Enter the string\n");
    gets(str);
    printf("\nEnter the sub string to find\n");
    gets(sub);
    puts(substring(str,sub));
    return 0;
}
