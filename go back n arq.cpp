#include<iostream>
#include<ctime>
#include<cstdlib>
#include<math.h>
using namespace std;
int a[100];
void create(int m,int n){
    int i,f1=0;
    m = pow(2,m);
    for(i=0;i<n;i++){
        if(f1==m){
            f1=0;
        }
        a[i]=f1;
        f1++;
    }
}
int main(){
    int no_f,N,m1;
    int no_tr=0;
    srand(time(0));
    cout<<"Enter the total number of frames : ";
    cin>>no_f;
    cout<<"Enter the value for m : ";
    cin>>m1;
    cout<<"Enter the Window Size : ";
    cin>>N;
    int i=0;
    create(m1,no_f);
    while(i<no_f){
        int x=0;
        for(int j=i;j<i+N && j<no_f;j++){
        cout<<"Sent Frame "<<a[j]<<endl;
        no_tr++;
        }
        for(int j=i;j<i+N && j<no_f;j++){
            int flag = rand()%2;
            if(!flag){
                cout<<"Acknowledgment of Frame "<<a[j]<<endl;
                x++;
            }
            else{
                cout<<"Frame "<<a[j]<<" Not Received"<<endl;
                cout<<"Retransmitting Window"<<endl;
                break;
            }
        }
        cout<<endl;
        i+=x;
    }
    cout<<"Total number of transmissions : "<<no_tr<<endl;
    return 0;
}
