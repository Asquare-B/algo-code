#include<stdio.h>
int main(){
    int n;
    int arr[100];
    int count=1;
    int cad[100];
    int choice;
    int target;
    int sum=0;
    printf("AALAP BHAKTA -- 19MIC0122\n ");
    printf("\n");
    printf("enter the size of set:");
    scanf("%d",&n);
    printf("enter the elements of the set:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    printf("enter the target:");
    scanf("%d",&target);
    while(1){
        printf("Enter:\n1-To enter the element%d of the candidate solution\n2-exit entering candidate elements:",count);
        scanf("%d",&choice);
        if(choice==1){
            printf("enter the element%d:",count);
            scanf("%d",&cad[count++]);
            sum=sum+cad[count-1];
        }
        else if(choice==2){
            break;
        }
    }
    int flag=0;
    for(int i=0;i<count;i++){
        for(int j=0;j<n;j++){
            if(cad[i]==arr[j]){
                flag++;
            }
        }
    }
    printf("\n");
    if(flag==count-1){
        if(sum==target){
            printf("True-since the sum of values of subset is equal to target");
        }
        else{
            printf("The given candidate solution is not actually a solutiona1");
        }
    }
    else{
        printf("The given candidate solution is not actually a solutiona2");
    }
    return 0;
}
