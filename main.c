#include <string.h>
#include <stdio.h>
#define LIM 1000

void itoa(int n, int b, char s[]);
void reverse(char s[]);
void dop(char s[], int b);



int main()
{
    int n, b;
    char str[LIM]=" ";

    printf("Задай n: ");
    scanf("%d", &n);
    printf("Задай b: ");
    scanf("%d", &b);
    printf("n=%d b=%d\n", n, b);
    
    itoa(n, b, str);
    printf("%s\n", str);

    return 0;
}

void itoa(int n, int b, char s[])
{
    int i, j, sign;
    if((sign=n)<0){
        n=-n;
    }
    i=0;
    do{
        s[i++]=n%10+'0';
    }
    while((n/=10)>0);
    
    if(sign<0){
        s[i++]='-';
    }

    s[i]='\0';
    dop(s,b);
    reverse(s);
}

void reverse(char s[])
{
    int i, j;
    char tmp;
    for(i=0, j=strlen(s)-1; i<j; ++i, --j)
    {
        tmp=s[j];
        s[j]=s[i];
        s[i]=tmp;
    }
}

void dop(char s[], int l2)
{
    int i, l;
    l=strlen(s);
    char SZ=s[l];
    if(l<l2)
    {        
        for(i=l; i<l2; ++i)
            {
                s[i]='0';
            }
        if(s[l-1]=='-')
        {
            char minus = s[l-1];
            s[l-1]='0';
            s[i]=minus;
        }
    }       
}

/*
if(l<l2)
    {
        s[l2]=SZ;
        if(s[l-1]!='-')
        {
            for(i=l; i<l2; ++i)
            {
                s[i]='0';
            }
        }
        else
        {
            char minus = s[l-1];
            for(i=l; i<l2; ++i)
            {
                s[i]='0';
            }
            s[l-1]='0';
            s[i]=minus;
        }                
    }
    */