#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> Array;
void printing(int f0, int f1){
    for(int x=0;x<Array.size();x++)
    {
        switch(Array[x])
        {
        case 1:
            cout<<"S"<<f0<<" ";
            f0++;
            break;
        case 0:
            cout<<"P"<<f1+1<<" ";
            f1++;
            break;
        }
    }
}

int main()
{
    int n,m,ord=1,t_m;
    int f0=1,f1=0;
    for(int x=0;x<50;x++){
        cout<<"*";
    }
    cout<<endl<<"AALAP BHAKTA 19MIC0122"<<endl;
    for(int x=0;x<50;x++){
        cout<<"*";
    }
    cout<<endl;
    do{
        cout<<"Enter the number of students:";
        cin>>n;
        cout<<"Enter the number of Professors:";
        cin>>m;
        if(n<m)
        {
            cout<<"n is smaller than m \nRe-";
        }
    }while(n<m);
    t_m=m;
    if(n>=m*2)
    {
        ord = 2;
        for(int x=0;x<n;x++)
        {
            Array.push_back(f0);
            if(t_m!=0)
            {
                if(ord%2==0)
                {
                    Array.push_back(f1);
                    if(ord==0)
                        ord=2;
                    t_m--;
                }
            }
            ord--;
        }
    }
    else
    {
        for(int x=0;x<n;x++)
        {
            Array.push_back(f0);
            if(t_m!=0)
            {
                Array.push_back(f1);
                t_m--;
            }
        }
    }
    printing(f0,f1);
    return 0;
}
