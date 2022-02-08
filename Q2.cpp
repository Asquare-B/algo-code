#include<stdio.h>
struct set
{
    int start;
    int end;
};
int count=0;
int temp[20];
int check(int n,int arr[n][n],int val)
{
    int flag=0;
    if(val<n)
    {
    for(int i=0;i<n;i++)
    {
        if(flag==n-1)
        {
            printf("OUTPUT:DISCONNECTED");
            exit(0);
        }
        if(arr[val][i]==1&&temp[val]==1)
        {
            count++;
            temp[val]=0;
            check(n,arr,val++);
        }
        else
        {
            flag++;
            continue;
        }
    }
    }
    else
    {
        return count;
    }
}
int main()
{
    int n;
    int cn;
    int arr[20][20];
    struct set s1[20];
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjaceny matrix of undirected graph:");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the number of set of edges:");
    scanf("%d",&cn);
    for(int i=0;i<cn;i++)
    {
        printf("enter the veritices of edge S%d:",i+1);
        scanf("%d",&s1[i].start);
        scanf("%d",&s1[i].end);
    }
    for(int i=0;i<cn;i++)
    {
        arr[s1[i].start-1][s1[i].end-1]=0;
        arr[s1[i].end-1][s1[i].start-1]=0;
    }
    for(int i=0;i<50;i++)
    {
        printf("*");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        temp[i]=1;
    }
    int counter;
    counter=check(n,arr,0);
    if(counter==n)
    {
        printf("OUTPUT:CONNECTED");
    }
    else
    {
        printf("OUTPUT:DISCONNECTED");
    }
    return 0;
}
