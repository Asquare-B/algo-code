#include<stdio.h>
struct nextindex{
    int row[30];
    int column[30];
}s1;
int main(){
    int inf=2147483647;
    int s;
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    int weight[9][9]={
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
    };
    int cost[9];
    int count=0;
    printf("enter the source vertex:");
    scanf("%d",&s);
    for(int i=0;i<9;i++){
        cost[i]=inf;
    }
    cost[s-1]=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(weight[i][j]==0){
                continue;
            }
            else{
                s1.row[count]=i;
                s1.column[count]=j;
                count++;
            }
        }
    }
    int val;
    for(int i=0;i<8;i++){
        for(int i=0;i<count;i++){
            if(cost[s1.row[i]]+weight[s1.row[i]][s1.column[i]]<cost[s1.column[i]]){
                val=weight[s1.row[i]][s1.column[i]]+cost[s1.row[i]];
                cost[s1.column[i]]=val;
            }
        }
    }
    printf("shortest distance from source to:\n");
    for(int i=0;i<9;i++){
        printf("vertex%d=%d\n",i+1,cost[i]);
    }
    return 0;
}
