#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int receiver(int);
int sen=0,ack=0;
void nopacket(int n1){
    int n= n1;
    int i;
    for(i=0;i<n;i++)
    {
        sender();
    }
}
void packetloss(int n){
    int i;
    int r;
    printf("Enter the frame number for which packet is lost:");
    scanf("%d",&r);
    for(i=0;i<n;i++)
    {
        if(r==i){
            printf("packet is lost so stopped transmission\n");
            break;
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
        if(r==i){
            sender1(r,i);
            break;
        }
        else{
            sender();
        }
    }
}

void sender1(int r, int j){
    int ak;
    printf("%d data is ready to send\n",sen);
    ack=receiver(sen);
    if(r==j){
        printf("not acknowledged %d so stop transmission\n",ack);
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
                packetloss(n);
                break;
            case 3:
                ackloss(n);
                break;
        }
        printf("1.continue 0. end");
        scanf("%d",&f);
    }while(f==1);
    return 0;
}
