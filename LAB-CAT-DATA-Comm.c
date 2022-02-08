#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count =0;
int receiver(int);
int sen=0,ack=0;
void both(int n){
    int i;
    int r,r1;
    int j=0;
    printf("Enter the frame number for which packet is lost:");
    scanf("%d",&r);
    printf("Enter the frame number for which ack is lost:");
    scanf("%d",&r1);
    for(i=0;i<n;i++)
    {
        if(r==i){
            printf("packet is lost and sending once again\n");
            sender();
            count++;
        }
        else{
            sender();
        }
    }
    for(i=0;i<n;i++){
        send1(r,i);
    }
}
void nopacket(int n1){
    int n= n1;
    int i;
    for(i=0;i<n;i++){
        sender();
    }
}
void packetloss(int n){
    int i;
    int r;
    int j=0;
    printf("Enter the frame number for which packet is lost:");
    scanf("%d",&r);
    for(i=0;i<n;i++)
    {
        if(r==i){
            printf("packet is lost and sending once again\n");
            sender();
            count++;
        }
        else{
            sender();
        }
    }
}
void ackloss(int n){
    int r,i;
    printf("Enter the frame number for which ack is lost:");
    scanf("%d",&r);
    for(i=0;i<n;i++){
        send1(r,i);
    }
}
void send1(int r, int j){
    int ak;
    printf("%d data is ready to send\n",sen);
    ack=receiver(sen);
    if(r==j){
        printf("not acknowledged %d so sends again\n",ack);
        r=10000;
        send1(r,j);
        count++;
    }
    else{
        printf("acknowledged %d\n",ak);
    }
    sen=ack;
}
void sender(){
    int ak;
    printf("%d data is ready to send\n",sen);
    ack=receiver(sen);
    printf("acknowledged %d\n",ak);
    sen=ack;
}
int receiver(int s1){
    printf("received data %d\n",s1);
    s1=(s1+1)%2;
    ack=s1;
    return ack;
}
int main(){

    srand(time(NULL));
    int n;
    int i,c,f=0;
    printf("Enter the number of packages:");
    scanf("%d",&n);
    do{
        printf("Options:\n\t1. no-packet loss\n\t2. packet loss\n\t3. acknowledgement loss\nEnter option no: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                nopacket(n);
                break;
            case 2:
                count =0;
                packetloss(n);
                break;
            case 3:
                count=0;
                ackloss(n);
                break;
            case 4:
                count =0;
                both(n);
                break;
        }
        printf("re transmitted frame count: %d\n",count);
        printf("\n1.continue 0. end");
        scanf("%d",&f);
    }while(f==1);
    return 0;
}
