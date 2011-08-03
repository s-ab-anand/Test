#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
char* getString(char* str)
{
    //char stringh[100];
    char* head=str;
    int c;
    int i=0;
    while((c=getchar()) != '\n'){
        *head=c;
        head++;
    }
    *head='\0';
    //puts(str);
    return str;
}
int match(char* str, char* patr)
{
    while(*patr)
    {
        if(*str++!=*patr++)
            return FALSE;
    }
    return TRUE;
}
void pattern(char* str, char* patr)
{
    //char* s=str;
    //char* r=patr;
    char* p=str;char* q=str;
    int len=strlen(patr);
    while(*q != '\0')
    {
        int matched=FALSE;
        while(match(q, patr))
        {
            matched=TRUE;
            q=q+len;
        }
        if(matched)
        {
            *p++='X';
        }
        //char* r=q;
        if(*q!='\0')
            *p++=*q++;
       // p=q;
    }
    *p='\0';
    puts(str);
}
int main()
{
    char* str;
    char patr[100];
    printf("Enter the string\n");
    //scanf("%c", str);
    str=getString(str);
    printf("Enter the pattern\n");
    //scanf("%c", patr);
    gets(patr);
    //printf("%s", str);
    puts(str);
    pattern(str, patr);
    //puts(str);
    return 0;
}
