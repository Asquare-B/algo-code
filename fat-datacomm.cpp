#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int receiver(int);
typedef struct packet{
    int data;
}p[100];
void sender(int d){
    int ak;
    ak=receiver(d);
    printf("acknowledged %d\n",ak);
}
int send1(int d, int r,int j){
    int ak;
    ak=receiver(d);
    if(j==r){
        printf("packet%d acknowledgement lost Re-send the window\n",d);
        r=1000;
        return -1;
    }
    else{
        printf("acknowledged %d\n",ak);
        return 0;
    }
}
void nopacket(int n1, packet p1[]){
    int i;
    if(n1%2!=0){
        for(i=0;i<(n1-1);i=i+2){
            printf("\n");
            printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
            for(int j=i;j<=i+1;j++){
                sender(p1[j].data);
            }
        }
        printf("\n");
        printf("packet%d is sent\n",p1[i].data);
        sender(p1[i].data);
    }
    else{
        for(int i=0;i<n1;i=i+2){
            printf("\n");
            printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
            for(int j=i;j<=i+1;j++){
                sender(p1[j].data);
            }
        }
    }

}
int receiver(int d1){
    printf("received packet%d\n",d1);
    int ak=d1;
    return ak;
}


void packetloss(int n, packet p1[]){
    int i;
    int r;
    int j=0;
    printf("Enter the frame number for which packet is lost:");
    scanf("%d",&r);
    if(n%2!=0){
        for(i=0;i<(n-1);i=i+2){
            printf("\n");
            if(i==r || (i+1)==r){
                printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                printf("packet%d is lost so Re-Transmit the window\n",p1[i].data);
                printf("packet%d and packet%d is re-sent\n",p1[i].data,p1[i+1].data);
                for(int j=i;j<=i+1;j++){
                    sender(p1[j].data);
                }
            }
            else{
                printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                for(int j=i;j<=i+1;j++){
                    sender(p1[j].data);
                }
            }
        }

        printf("\n");
        if(i==r){
            printf("packet%d is sent\n",p1[i].data);
            printf("packet%d is lost so Re-Transmit the window\n",p1[i].data);
            printf("packet%d is re-sent\n",p1[i].data);
            sender(p1[i].data);
        }
        else{
            printf("packet%d is sent\n",p1[i].data);
            sender(p1[i].data);
        }
    }
    else{
        for(i=0;i<n;i=i+2){
            printf("\n");
            if(i==r || (i+1)==r){
                printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                printf("packet%d is lost so Re-Transmit the window\n",p1[i].data);
                printf("packet%d and packet%d is re-sent\n",p1[i].data,p1[i+1].data);
                for(int j=i;j<=i+1;j++){
                    sender(p1[j].data);
                }
            }
            else{
                printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                for(int j=i;j<=i+1;j++){
                    sender(p1[j].data);
                }
            }
        }
    }
}

void ackloss(int n, packet p1[]){
    int i,r;
    int j=0;
    printf("Enter the frame number for which acknowledgement is lost:");
    scanf("%d",&r);
    if(n%2!=0){
        for(i=0;i<(n-1);i=i+2){
            printf("\n");
                printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                for(int j=i;j<=i+1;j++){
                    int r1 = send1(p1[j].data,r,j);
                    if(r1==-1){
                        r=1000;
                        printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                        for(int j=i;j<=i+1;j++){
                            sender(p1[j].data);
                        }
                    }
                }
        }
        printf("\n");
        printf("packet%d is sent\n",p1[i].data);
        int r2 = send1(p1[i].data,r,i);
        if(r2==-1){
            r=1000;
            printf("packet%d is sent\n",p1[i].data);
            sender(p1[i].data);
        }
    }
    else{
        for(i=0;i<n;i=i+2){
            printf("\n");
                printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                for(int j=i;j<=i+1;j++){
                    int r1 = send1(p1[j].data,r,j);
                    if(r1==-1){
                        r=1000;
                        printf("packet%d and packet%d is sent\n",p1[i].data,p1[i+1].data);
                        for(int j=i;j<=i+1;j++){
                            sender(p1[j].data);
                        }
                    }
                }
        }
    }
}
int main(){
    srand(time(NULL));
    int n;
    int i,c,f=0;
    printf("Enter the number of packages:");
    scanf("%d",&n);
    packet p[n];
    for(int i=0;i<n;i++){
        p[i].data=i;
    }
    do{
        printf("Options:\n\t1. no-packet loss\n\t2. packet loss\n\t3. acknowledgement loss\nEnter option no: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                nopacket(n,p);
                break;
            case 2:
                packetloss(n,p);
                break;
            case 3:
                ackloss(n,p);
                break;
        }
        printf("\n1.continue 0. end");
        scanf("%d",&f);
    }while(f==1);
    return 0;
}
