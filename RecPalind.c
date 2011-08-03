#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rec(char* q, char* r)
{
    if(*q && *r)
    {
        if(*q!=*r)
            return 0;
        q++;
        r--;
        rec(q,r);
    }
    return 1;

}
int recPalind(char* string)
{
    char* p=string;
    char* q; char* r;
    int count=0;
    while(*p)
    {
            count+=1;
            p+=1;
    }
    if(count%2!=0)
    {
        q=string+(count/2-1);
        r=string+(count/2+1);
    }
    else
    {
        q=string+count/2;
        r=q-1;
    }
    return rec(q,r);
}
int main()
{
    char string[100];
    gets(string);
    if(recPalind(string))
        printf("\nString is a palindrome");
    else
        printf("\nString not a palindrome");
    return 0;
}
