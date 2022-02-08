#include<stdio.h>
int add(int x,int y,int c){
    return x+y+c;
}
int carry(int s){
    if(s==0){
        return 0;
    }
    else if(s==1){
        return 0;
    }
    else if(s==2){
        return 1;
    }
    else if(s==3){
        return 1;
    }
}

int main(){
    int a[10],b[10],c[10],n,i,j,l1,l2,l3;
    printf("Enter n:");
    scanf("%d",&n);
    int q=n;
    for(i=0;q>0;i++){
        a[i]=q%2;
        q=q/2;
    }
    l1=i;
    for(i=3,j=0;i>=0;i--,j++){
        c[j]=a[i];
    }
    printf("\n");
    l2=j;
    for(i=4,j=3;i<l1;i++,j--){
        b[j]=a[i];
    }
    l3=j;
    for(i=l3;i>=0;i--){
        b[i]=0;
    }
    printf("\n\nhello\n");

    for(i=0;i<4;i++){
        printf("%d",b[i]);
    }
    printf("\n");
    for(i=0;i<4;i++){
        printf("%d",c[i]);
    }
    int sum[10],c1=0;
    for(i=0;i<4;i++){
        sum[i]=add(b[i],c[i],c1);
        c1=carry(sum[i]);
    }
    printf("\n\nSum:");
    for(i=0;i<4;i++){
        printf("%d",sum[i]);
    }
    return 0;
}
