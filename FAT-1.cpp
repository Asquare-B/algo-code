#include <bits/stdc++.h>
using namespace std;

class Banks{
    public:
        int max_d(int* distance, int n){
            int m1 = 0;
            for (int x = 0; x < n; x++) {
                if (distance[x] > distance[m1])
                    m1 = x;
            }
            return m1;
        }
        void selection(int n, int Graph[10][10], int k){
            int* distance = new int[n];
            vector<int> vertexAtm;
            for (int x = 0; x < n; x++) {
                distance[x] = INT_MAX;
            }
            int h = 0;
            for (int x = 0; x < k; x++) {
                vertexAtm.push_back(h);
                for (int j = 0; j < n; j++) {
                    distance[j] = min(distance[j], Graph[h][j]);
                }
                h = max_d(distance, n);
            }
            for (int x = 0; x < vertexAtm.size(); x++) {
                cout << vertexAtm[x] << " ";
            }
        }
}a1;
int main(){
	int size_n,k;
	int Graph[10][10];
	for(int x=0;x<50;x++){
        cout<<"*";
    }
    cout<<endl<<"AALAP BHAKTA 19MIC0122"<<endl;
    for(int x=0;x<50;x++){
        cout<<"*";
    }
    cout<<endl;
	cout<<"Enter number of vertices: ";
	cin>>size_n;
	cout<<"Enter the undirected weighted graph matrix: "<<endl;
	for(int x=0;x<size_n;x++){
        for(int j=0;j<size_n;j++){
            cin>>Graph[x][j];
        }
	}
	cout<<"Enter k: ";
	cin>>k;
	a1.selection(size_n, Graph, k);
}

