#include<stdio.h>
#include<stdlib.h>

char* getString(char* str)
{
    //char stringh[100];
    char* head=str;
    int c;
    //int i=0;
    while((c=getchar()) != '\n'){
        *head=c;
        head++;
    }
    *head='\0';
    //puts(str);
    return str;
}
void revWord(char* str)
{
    if(*str)
    {
        char* p=str;
        char*q=p;
        while(*str!=' ' && *str!='\0')
        {
            *p++=*str++;
        }
        //p=str;
        *p='\0';
        str++;
        revWord(str);
        printf("%s", q);
        printf(" ");
    }
}
int main()
{
    char str[100]="";
    getString(str);
    revWord(str);
    return 0;
}
