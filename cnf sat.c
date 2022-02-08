#include<stdio.h>
#include<string.h>
int main(){
    char ch[100];
    int arr[100];
    int x,y,z;
    int sum=0,count=0;
    int bposition[100];
    int start,end;
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    printf("enter the 3CNF-SAT equation by using,\nliterals:x,y,z\nnegation of literals:~x,~y,~z\nor:V\nand:^\n");
    scanf("%s",ch);
    printf("enter the values of x,y,z:");
    scanf("%d%d%d",&x,&y,&z);
    for(int i=0;i<strlen(ch);i++){
        if(ch[i]==')'){
            bposition[count++]=i;
        }
    }
    for(int k=0;k<count;k++){
        sum=0;
        if(k==0){
            for(int i=0;i<=bposition[k];i++){
                if(ch[i]=='~'){
                    i=i+1;
                    switch(ch[i]){
                        case 'x':
                            sum=sum||(!x);
                            break;
                        case 'y':
                            sum=sum||(!y);
                            break;
                        case 'z':
                            sum=sum||(!z);
                            break;
                    }
                }
                else{
                    switch(ch[i]){
                        case 'x':
                            sum=sum||(x);
                            break;
                        case 'y':
                            sum=sum||(y);
                            break;
                        case 'z':
                            sum=sum||(z);
                            break;
                    }
                }
            }
            arr[k]=sum;
        }
        else{
            start=bposition[k-1]+1;
            end=bposition[k];
            for(int i=start;i<=end;i++){
                if(ch[i]=='~'){
                    i=i+1;
                    switch(ch[i]){
                        case 'x':
                            sum=sum||(!x);
                            break;
                        case 'y':
                            sum=sum||(!y);
                            break;
                        case 'z':
                            sum=sum||(!z);
                            break;
                    }
                }
                else{
                    switch(ch[i]){
                        case 'x':
                            sum=sum||(x);
                            break;
                        case 'y':
                            sum=sum||(y);
                            break;
                        case 'z':
                            sum=sum||(z);
                            break;
                    }
                }
            }
            arr[k]=sum;
        }
    }
    int sum1=1;
    for(int i=0;i<count;i++){
        sum1=sum1&&arr[i];
    }
    printf("\n");
    printf("ANSWER:\n");
    if(sum1==1){
        printf("True-The given 3NF-SAT equation is satisfiable for the given candidate solution.");
    }
    else if(sum1==0){
        printf("The given candidate solution is not actually a solution");
    }
    return 0;
}
