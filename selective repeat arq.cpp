#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctime>
int m,senwin;
int receiver(int);
void sender(int f)
{
    int receivedack;
    printf("frame%d is sent to the receiver\n",f);
    receivedack=receiver(f);
    m:
    if(receivedack==-f)
    {
        printf("frame%d is sent to the receiver\n",f);
        receivedack=receiver(f);
        goto m;
    }
}
int receiver(int f)
{
    int n;
    srand(time(0));
    n = rand()%2;
    if(!n)
    {
        if(f==senwin-1)
        {
            printf("*ALL PACKETS IN THE SENDWINDOW RECEIVED COMPLETELY\n*");
            printf("ACK%d is sent to sender\n",0);
            return 0;
        }
        else
        {
            printf("ACK%d is sent to sender\n",f+1);
            return f+1;
        }
    }
    else
    {
        printf("NACK%d is sent to receiver\n",-f);
        return -f;
    }
}
int main()
{
    int minlimit=0,maxlimit=0;
    printf("enter the :\n");
    scanf("%d",&m);
    senwin=(int)pow(2,m-1);
    int a[m];
    printf("enter the frames:\n");
    for(int i=0;i<senwin;i++)
    {
        a[i]=i;
    }
    minlimit=0;
    maxlimit=m;
    for(int i=1;i<=senwin/m;i++)
    {
        for(int j=minlimit;j<maxlimit;j++)
        {
            sender(a[j]);
        }
        minlimit=maxlimit;
        maxlimit+=m;
    }
}
