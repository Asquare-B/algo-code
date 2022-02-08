#include<stdio.h>
int main(){
    int sum;
    int inf=2147483647;
    int arr[4][4]={
        {0,3,inf,7},
        {8,0,2,inf},
        {5,inf,0,1},
        {2,inf,inf,0}
    };
    int u,v;
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    printf("enter the value of u:");
    scanf("%d",&u);
    printf("enter the value of v:");
    scanf("%d",&v);
    int temp[4];
    for(int k=0;k<v;k++){
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
        temp[k]=arr[u][v];
    }
    printf("All pair shortest path:\n");
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
    printf("\n");
    for(int i=0;i<4;i++){
        if(temp[i]==arr[u][v]){
            printf("Shortest path and distance between %d and %d:\n",u,v);
            for(int k=0;k<50;k++){
                printf("*");
            }
            printf("\n");
            printf("\tShortest path:%d->%d->%d\n",u,i,v);
            printf("\tShortest distance:%d",arr[u][v]);
            break;
        }
    }
    return 0;
}
