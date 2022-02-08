#include <iostream>
#include<math.h>
using namespace std;
inline int isPerfectSquare(int n){
	if (n >= 0){
		long i = sqrt(n);
		if(i * i == n){
            return 0;
		}
	}
	return 1;
}

int main(){
    for(int i=0;i<50;i++){
        cout<<"*";
    }
    cout<<endl<<"AALAP BHAKTA - 19MIC0122"<<endl;
    for(int i=0;i<50;i++){
        cout<<"*";
    }
    cout<<endl;
	int n;
	cout<<"Enter a number to check perfect square: ";
	cin>>n;
	if (isPerfectSquare(n) == 0)
		cout << "YES, its a perfect square"<<endl;
	else
		cout << "No, its NOT a perfect square"<<endl;
	return 0;
}
