#include <math.h>
#include <stdio.h>
#include<string.h>
char trans[100]="001";
char syn[4];
void senderHC4(char ip1[]){
    printf("Forming the transfer CodeWord\n");
    char r0,r1,r2;
    r0 = (char)((int)ip1[3] + (int)ip1[2] + (int)ip1[1])%2;
    r1 = (char)((int)ip1[2] + (int)ip1[1] + (int)ip1[0])%2;
    r2 = (char)((int)ip1[3] + (int)ip1[0] + (int)ip1[2])%2;
    strcat(trans,r2);
    strcat(trans,r1);
    strcat(trans,r0);
    strcat(trans,ip1);
    printf("\n transferring code: ");
    printf("%s",trans);
}

void senderHC5(char input[]){
    printf("Forming the transfer CodeWord\n");
    int r0,r1,r2,r3,i,j;
    r0 = (input[4] + input[3] + input[2] + input[1])%2;
    r1 = (input[3] + input[2] + input[1] + input[0])%2;
    r2 = (input[4] + input[3] + input[2] + input[0])%2;
    r3 = (input[4] + input[3] + input[1] + input[0])%2;
    trans[0] = r3;
    trans[1] = r2;
    trans[2] = r1;
    trans[3] = r0;
    for(i=4,j=0;i<9;i++,j++){
        trans[i]=input[j];
    }
    printf("\n transferring code: ");
    for(i=0;i<9;i++){
        printf("%d",trans[i]);
    }
}
void receiverHC4(){
    printf("Forming the syndrome bits for checking the CodeWord\n");
    int s0,s1,s2,i,j;
    s0 = (trans[6] + trans[5] + trans[4] + trans[2])%2;
    s1 = (trans[5] + trans[4] + trans[3] + trans[1])%2;
    s2 = (trans[5] + trans[3] + trans[6] + trans[0])%2;
    if(s2==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    if(s1==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    if(s0==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    printf("\n checking for error");
    if(strcmp(syn,"000")==0){
        printf("no error");
    }
    else{
        printf("flip the error bit and checking");
        if(strcmp(syn,"001")==0){
            switch(trans[2]){
                case 0:
                    trans[2]=1;
                    break;
                case 1:
                    trans[2]=0;
                    break;
            }
        }
        if(strcmp(syn,"010")==0){
            switch(trans[1]){
                case 0:
                    trans[1]=1;
                    break;
                case 1:
                    trans[1]=0;
                    break;
            }
        }
        if(strcmp(syn,"011")==0){
            switch(trans[4]){
                case 0:
                    trans[4]=1;
                    break;
                case 1:
                    trans[4]=0;
                    break;
            }
        }
        if(strcmp(syn,"100")==0){
            switch(trans[0]){
                case 0:
                    trans[0]=1;
                    break;
                case 1:
                    trans[0]=0;
                    break;
            }
        }
        if(strcmp(syn,"101")==0){
            switch(trans[6]){
                case 0:
                    trans[6]=1;
                    break;
                case 1:
                    trans[6]=0;
                    break;
            }
        }
        if(strcmp(syn,"110")==0){
            switch(trans[3]){
                case 0:
                    trans[3]=1;
                    break;
                case 1:
                    trans[3]=0;
                    break;
            }
        }
        if(strcmp(syn,"111")==0){
            switch(trans[5]){
                case 0:
                    trans[5]=1;
                    break;
                case 1:
                    trans[5]=0;
                    break;
            }
        }
        printf("\n error bit are changed and checking once again");
    }
}
void receiverHC5(){
    printf("Forming the syndrome bits for checking the CodeWord\n");
    int s0,s1,s2,s3,i,j;
    s0 = (trans[8] + trans[7] + trans[6] + trans[5] + trans[3])%2;
    s1 = (trans[7] + trans[6] + trans[5] + trans[4] + trans[2])%2;
    s2 = (trans[8] + trans[7] + trans[6] + trans[4] + trans[1])%2;
    s3 = (trans[8] + trans[7] + trans[5] + trans[4] + trans[0])%2;
    if(s3==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    if(s2==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    if(s1==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    if(s0==1)
        strcat(syn,"1");
    else
        strcat(syn,"0");
    printf("\n checking for error");
    if(strcmp(syn,"0000")==0){
        printf("no error");
    }
    else{
        printf("flip the error bit and checking");
        if(strcmp(syn,"0001")==0){
            switch(trans[3]){
                case 0:
                    trans[3]=1;
                    break;
                case 1:
                    trans[3]=0;
                    break;
            }
        }
        if(strcmp(syn,"0010")==0){
            switch(trans[2]){
                case 0:
                    trans[2]=1;
                    break;
                case 1:
                    trans[2]=0;
                    break;
            }
        }
        if(strcmp(syn,"0100")==0){
            switch(trans[1]){
                case 0:
                    trans[1]=1;
                    break;
                case 1:
                    trans[1]=0;
                    break;
            }
        }
        if(strcmp(syn,"1000")==0){
            switch(trans[0]){
                case 0:
                    trans[0]=1;
                    break;
                case 1:
                    trans[0]=0;
                    break;
            }
        }
        if(strcmp(syn,"1110")==0){
            switch(trans[4]){
                case 0:
                    trans[4]=1;
                    break;
                case 1:
                    trans[4]=0;
                    break;
            }
        }
        if(strcmp(syn,"1011")==0){
            switch(trans[5]){
                case 0:
                    trans[5]=1;
                    break;
                case 1:
                    trans[5]=0;
                    break;
            }
        }
        if(strcmp(syn,"0111")==0){
            switch(trans[6]){
                case 0:
                    trans[6]=1;
                    break;
                case 1:
                    trans[6]=0;
                    break;
            }
        }
        if(strcmp(syn,"1111")==0){
            switch(trans[7]){
                case 0:
                    trans[7]=1;
                    break;
                case 1:
                    trans[7]=0;
                    break;
            }
        }
        if(strcmp(syn,"1101")==0){
            switch(trans[8]){
                case 0:
                    trans[8]=1;
                    break;
                case 1:
                    trans[8]=0;
                    break;
            }
        }
        printf("\n error bit are changed and checking once again");
        receiverHC5();
    }
}
void main(){
    char ip[10];
    int i,j,l;
    int f=1;
    while(f!=0){
        int c;
        printf("Options \n\t1.sender 4bit\n\t2.sender 5bit\n\t3.receiver 4bit\n\t4.receiver 5bit\n\n Enter choice");
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("Enter input:");
                scanf("%s",ip);
                l = strlen(ip);
                senderHC4(ip);
                break;
            case 2:
                printf("Enter input:");
                scanf("%s",ip);
                l = strlen(ip);
                for(i=0,j=l-1;i<l;i++,j--){
                    if(ip[j]=='1')
                        ip[i]=1;
                    else
                        ip[i]=0;
                }
                senderHC5(ip);
                break;
            case 3:
                printf("Enter transferring code input:");
                scanf("%s",ip);
                l = strlen(ip);
                for(i=0;i<l;i++){
                    if(ip[i]=='1')
                        trans[i]=1;
                    else
                        trans[i]=0;
                }
                receiverHC4();
                break;
            case 4:
                printf("Enter transferring code input:");
                scanf("%s",ip);
                l = strlen(ip);
                for(i=0;i<l;i++){
                    if(ip[i]=='1')
                        trans[i]=1;
                    else
                        trans[i]=0;
                }
                receiverHC5();
                break;
        }
        printf("\nEnter 1 for continue or 0 for exit:");
        scanf("%d",&f);
    }
}
