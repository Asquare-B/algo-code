#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int cn;
    int temp[100];
    int arr[100][100];
    int cad[100];
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    printf("enter the number of vertices:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        temp[i]=1;
    }
    printf("enter the adjacency matrix of graph:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the number of elements going to be entered in proposed candidate solution:");
    scanf("%d",&cn);
    printf("enter the proposed candidate solution:");
    for(int i=0;i<cn;i++){
        scanf("%d",&cad[i]);
    }
    printf("\n");
    int val,flag=0;
    for(int i=0;i<cn;i++){
        val=cad[i]-1;
        for(int i=0;i<n;i++){
            if(arr[val][i]==1){
                flag=1;
            }
        }
        if(flag==0){
            printf("the given candidate solution is not actually a solution");
            exit(0);
        }
        else if(flag==1){
            temp[val]=0;
            for(int i=0;i<n;i++){
                if(arr[val][i]==1){
                    temp[i]=0;
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(temp[i]==0){
            count++;
            continue;
        }
        else if(temp[i]==1){
            printf("the given candidate solution is not actually a solution");
            exit(0);
        }
    }
    if(count==n){
        printf("True - the given candidate solution is actually a vertex cover.");
    }
    else{
        printf("the given candidate solution is not actually a solution");
    }
    return 0;
}
