#include<stdio.h>
int main(){
    int sum;
    int inf=2147483647;
    int arr[4][4]={
        {0,5,inf,8},
        {inf,0,inf,inf},
        {inf,3,0,1},
        {inf,inf,inf,0}
    };
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(arr[i][k]==inf||arr[k][j]==inf){
                    sum=inf;
                }
                else{
                    sum=arr[i][k]+arr[k][j];
                }
                if(arr[i][j]>sum){
                    arr[i][j]=sum;
                }
            }
        }
    }
    printf("Shortest distance matrix:\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(arr[i][j]==inf){
                printf("%s","INF\t");
            }
            else{
                printf("%d\t",arr[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}
