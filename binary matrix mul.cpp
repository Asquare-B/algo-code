#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class Matrix{
    int A[10][10];
    int B[10][10];
    int C[10][10];
    int r1[10][10], mul[10][10];
    int val[10][10], val1[10][10];
    int zero_flag=0;
    int f=0;
    public:
        void input(int n){
             for(int l=0;l<4;l++){
                switch(l){
                    case 1:
                        cout<<"A:"<<endl;
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                cin>>A[i][j];
                            }
                        }
                        break;
                    case 2:
                        cout<<"B:"<<endl;
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                cin>>B[i][j];
                            }
                        }
                        break;
                    case 3:
                        cout<<"C:"<<endl;
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                cin>>C[i][j];
                            }
                        }
                        break;
                }
             }
        }
        void create_binary_array(int n){
            int c=0;
            zero_flag=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<1;j++){
                    r1[i][j]=rand()%2;
                    if(r1[i][j]==0){
                        c++;
                    }
                }
            }
            if(c==n){
                zero_flag=1;
            }
        }
        int isEqual(int n){
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if (val[i][j] != val1[i][j])
                        return 1;
            return 0;
        }
        void multi_mat(int n){
            for(int x=0;x<pow(2,n);x++){
                create_binary_array(n);
                if(zero_flag==1){
                    continue;
                }
                else{
                    for(int i=0;i<n;i++){
                        for(int j=0;j<1;j++){
                            mul[i][j]=0;
                            for(int k=0;k<n;k++){
                                mul[i][j]+=B[i][k]*r1[k][j];
                            }
                        }
                    }
                    for(int i=0;i<n;i++){
                        for(int j=0;j<1;j++){
                            val[i][j]=0;
                            for(int k=0;k<n;k++){
                                val[i][j]+=A[i][k]*mul[k][j];
                            }
                        }
                    }
                }
                for(int i=0;i<n;i++){
                    for(int j=0;j<1;j++){
                        val1[i][j]=0;
                        for(int k=0;k<n;k++){
                            val1[i][j]+=C[i][k]*r1[k][j];
                        }
                    }
                }
                f=isEqual(n);
                if(f==0){
                    match_equal(n);
                }
                else{
                    not_equal(n);
                }

            }
        }
        void match_equal(int n){
            cout<<"YES => BIT VECTOR r :";
            for(int i=0;i<n;i++){
                for(int j=0;j<1;j++){
                    cout<<r1[i][j];
                }
            }
            cout<<endl;
        }
        void not_equal(int n){
            cout<<"NO => BIT VECTOR r :";
            for(int i=0;i<n;i++){
                for(int j=0;j<1;j++){
                    cout<<r1[i][j];
                }
            }
            cout<<endl;
        }
}m;
int main(){
    int n1=3;
    printf("enter the size of the matrix:");
    scanf("%d",&n1);
    m.input(n1);
    m.multi_mat(n1);
}
