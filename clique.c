#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    int cn;
    int arr[100][100];
    int cad[100];
    int temp[100];
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    printf("enter the number of vertices:");
    scanf("%d",&n);
    printf("enter the adjacency matrix of the graph:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the number of elements to be entered in candidate solution:");
    scanf("%d",&cn);
    printf("enter the proposed candidate solution:");
    for(int i=0;i<cn;i++){
        scanf("%d",&cad[i]);
    }
    printf("\n");
    int val;
    int count=0;
    int count1=0;
    for(int i=0;i<cn;i++){
        if(cad[i]<=n){
            continue;
        }
        else{
            printf("the given candidate solution is not actually a solution");
            exit(0);
        }
    }
    for(int i=0;i<cn;i++){
        count=1;
        val=cad[i]-1;
        for(int j=0;j<cn;j++){
            temp[cad[j]-1]=1;
        }
        temp[val]=2;
        for(int k=0;k<n;k++){
            if(arr[val][k]==1&&temp[k]==1){
                temp[k]=2;
                count++;
            }
        }
        if(count==cn){
            count1++;
            continue;
        }
        else{
            printf("the given candidate solution is not actually a solution");
            exit(0);
        }
    }
    if(count1==cn){
        printf("True - the given candidate solution forms a Clique");
    }
    else{
        printf("the given candidate solution is not actually a solution");
    }
    return 0;
}
