#include<stdio.h>
int main(){
    int n;
    int arr[100][100];
    int weight[100][100];
    int choice;
    int count=0;
    int cad[100];
    int temp[100];
    printf("AALAP BHAKTA -- 19MIC0122\n");
    printf("\n");
    printf("enter the total number of edges:");
    scanf("%d",&n);
    printf("enter the adjacency matrix for the graph:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("enter the weighted matrix for the graph:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&weight[i][j]);
        }
    }
    while(1){
        printf("Enter:\n1-To enter the element%d of the proposed candidate solution\n2-exit entering proposed candidate elements:",count+1);
        scanf("%d",&choice);
        if(choice==1){
            printf("enter the element%d:",count+1);
            scanf("%d",&cad[count++]);
        }
        else if(choice==2){
            break;
        }
    }
    printf("\n");
    int count1=0;
    for(int i=0;i<count-1;i++){
        int flag=0;
        for(int j=i+1;j<count-1;j++){
            if(cad[i]==cad[j]){
                printf("The given candidate solution is not actually a solution\n");
                exit(0);
                flag=1;
            }
        }
        if(flag==0){
            temp[count1++]=cad[i];
        }
    }
    temp[count1++]=cad[n];
    printf("The given candidate solution is:");
    for(int i=0;i<count1;i++){
        printf("%d ",temp[i]);
    }
    printf("\n");
    int sum=0;
    printf("True-the given candidate solution is correct\n");
    printf("summation of cost of the given candidate solution:");
    for(int i=0;i<count1-1;i++){
        if(i!=count1-2){
            printf("%d-",weight[temp[i]-1][(temp[i+1]-1)]);
            sum=sum+weight[temp[i]-1][(temp[i+1]-1)];
        }
        else{
            printf("%d\n",weight[temp[i]-1][(temp[i+1]-1)]);
            sum=sum+weight[temp[i]-1][(temp[i+1]-1)];
        }
    }
    printf("Total cost:%d",sum);
}

