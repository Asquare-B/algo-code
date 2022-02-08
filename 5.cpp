#include<time.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> R;

int main(){
    int n,k,flag_0=0;
	srand(time(0));
	do{
        cout<<"Enter the 'N':";
        cin>>n;
        if((n%2!=0) || (n>10)){
            cout<<"Value of 'N' should be even and less than 10.\nRe-";
        }
	}while((n%2!=0) || (n>10));
    cout<<"\nR:\t";
    for(int i=0;i<n;i++){
        R.push_back(rand()%2);
        cout<<R[i]<<"\t";
    }

    cout<<"\n\nAnswer:\n";
	for(int i=0; i<n/2; i++){
		k = rand()%n;
		if(R[k]==1)
            cout<<"Index: "<<k<<"\n";
        else{
                cout<<"Fail";
                return 0;
        }
    }
    cout<<"The majority of entries of R is 1 only";
	return 0;
}
