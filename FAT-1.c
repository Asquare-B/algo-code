#include<stdio.h>
int main()
{
    int n;
    int m;
    int z=0;
    printf("enter the number of students:");
    scanf("%d",&n);
    printf("enter the number of professors:");
    scanf("%d",&m);;
    char arr3[100];
    int temp1=n;
    int temp2=m;
    if(n>=m)
    {
    while(z<n+m)
    {
        if(z==0)
        {
            arr3[z]='S';
            z++;
            temp1--;
        }
        else
        {
            if(arr3[z-1]=='P'&&temp1>0)
            {
                arr3[z]='S';
                z++;
                temp1--;
            }
            else if(arr3[z-1]=='S'&&temp2>0)
            {
                arr3[z]='P';
                z++;
                temp2--;
            }
            else if(arr3[z-1]=='S'&&temp2<0&&temp1>0)
            {
                arr3[z]='S';
                z++;
            }
        }
    }
    }
    printf("The MAXIMUM INTERACTION POSSIBLE:");
    for(int i=0;i<z;i++)
    {
        printf("%c ",arr3[i]);
    }
}
