#include<stdio.h>
#include<string.h>
int tot=0;
struct code{
    char a[20];
}c1[100];
char oddp1(char *a)
{
    int count=0;
    char flag;
    int i;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='1')
        {
            count++;
        }
    }
    if (count%2!=0)
    {
        flag='0';
    }
    else
    {
        flag='1';
    }
    return flag;
}
int oddp(char *a){
    int count=0;
    char flag;
    int i;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='1')
        {
            count++;
        }
    }
    if (count%2!=0)
    {
        flag=0;
    }
    else
    {
        flag=1;
    }
    return flag;
}
void rec()
{
    int n,n1,i,j;
    char arr[500];
    int c;
    printf("enter the merged code word from sender:");
    scanf("%s",arr);
    printf("enter the total number of code words merged at sender:");
    scanf("%d",&n);
    printf("enter the number of bits in codeword(without parity bit):");
    scanf("%d",&n1);
    n1=n1+1;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n;j++)
        {
            c1[j].a[i]=arr[tot];
            tot++;
        }
        c1[i].a[n1]='\0';
    }
    for(i=0;i<n;i++)
    {
        c=oddp(c1[i].a);
        if(c==0)
        {
            printf("%s has no error (since of odd parity)\n",c1[i].a);
        }
        else
        {
            printf("%s has error (since of even parity)\n",c1[i].a);
        }
    }
}
void sender()
{
    int n,i,j;
    char c,arr[500];
    printf("enter the number of codewords:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",c1[i].a);
    }
    c=oddp(c1[1].a);
    for(i=0;i<n;i++)
    {
        c=oddp1(c1[i].a);
        c1[i].a[strlen(c1[i].a)]=c;
        c1[i].a[strlen(c1[i].a)+1]='\0';
    }
    printf("after adding odd parity bit:\n");
    for(i=0;i<n;i++)
    {
        puts(c1[i].a);
    }
    for(i=0;i<strlen(c1[1].a);i++)
    {
        for(j=0;j<n;j++)
        {
            arr[tot]=c1[j].a[i];
            tot++;
        }
    }
    arr[tot]='\0';
    printf("Final result of merging code word from sender:\n");
    for(i=0;i<arr[i]!='\0';i++)
    {
        printf("%c",arr[i]);
    }
}
void main(){
    int f=1,n;
    while(f!=0){
    printf("OPTIONS:\n\t1.Sender side\n\t2.Receiver side\n\nEnetr choice:");
    scanf("%d",&n);
        if(n==1){
            sender();
        }
        else if(n==2){
            rec();
        }
        printf("\n\n 1 for continue and 0 for exit");
        scanf("%d",&f);
    }
}
