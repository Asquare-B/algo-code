#include<stdio.h>
int receiver(int);
int sen=0,ack=0;
void sender()
{
    int ak;
    printf("%d data is ready to send\n",sen);
    ack=receiver(sen);
    printf("acknowledged %d\n",ak);
    sen=ack;
}
int receiver(int s1)
{
    printf("received data %d\n",s1);
    s1=(s1+1)%2;
    ack=s1;
    return ack;
}
int main()
{
    int n;
    int i;
    printf("Enter the number of packages:");
    scanf("%d",&n);
    for(i=0;i<=n;)
    {
        sender();
        i++;
    }
    return 0;
}
