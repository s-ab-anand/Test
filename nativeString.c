#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int match(char* text, char* patt, char spl)
{
    int n=strlen(text);
    int m=strlen(patt);
    int i,j, flag;
    for(i=0;i<n-m+1; i++)
    {
        flag=1;
        for(j=0;j<m && flag==1;j++)
        {
            int count=0;
            if(patt[j]!=text[i+j+count] && patt[j]!=spl)
            {
                flag=0;
                i=i+j+1;
                break;
            }
            if(patt[j]==spl)
            {
                //int count=0;
                j++;
                while(text[i+j+count]!=patt[j] && i+j+count<n)
                    count++;
                if(!(i+j+count<n))
                    flag=0;
            }

        }
        if(flag)
            return flag;
    }
    return flag;
}
int main()
{
    char text[100];
    char patt[100];
    char c;
    printf("Enter the text\n");
    gets(text);
    printf("\nEnter the pattern\n");
    gets(patt);
    printf("\nSpecify the special character in the pattern\n");
    c=getchar();
    if(match(text, patt,c))
    {
        printf("text found\n");
    }
    else
        printf("text not found");
    return 0;
}
