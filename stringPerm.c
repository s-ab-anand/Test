#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void perm(char* str, char* fi, const int si)
{
    if(*str)
    {
        if(!(*fi))
        {
            char* q=fi;
            *q++=*str;
            *q='\0';
            //printf("%s\n", fi);
            perm(str+1, fi, si);
        }
        else
        {
            char p[100];
            int len=strlen(fi);
            int i;
            for(i=0; i<=len; i++)
            {
                memcpy(p, fi, len);
                int j=len;
                if(i!=len)
                {
                    p[j+1]='\0';
                    while(j!=i)
                    {
                        p[j]=p[j-1];
                        j-=1;
                    }
                    p[j]=*str;
                    if(strlen(p)==si)
                        puts(p);
                    perm(str+1, p,si);
                }
                else
                {
                    p[j]=*str;
                    p[j+1]='\0';
                    if(strlen(p)==si)
                        puts(p);
                    perm(str+1, p, si);
                }
            }

        }

    }

}
int main()
{
    printf("Enter the string\t");
    char str[100];
    char fi[100];
    fi[0]=NULL;
    //memcpy(fi, 0, sizeof(fi));
    gets(str);
    const int si=strlen(str);
    perm(str, fi, si);
    return 0;
}
