#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> I;
vector<int> U;
vector<vector<vector<int>>> S;
vector<int> visited_sets;
int INF = INT_MAX;

void input_I(vector<int> in)
{
    for(int i=0;i<in.size();i++)
    {
        int flag = 1;
        for(int j=0;j<I.size();j++)
            if(in[i]==I[j])
            {
                flag=0;
                break;
            }
        if(flag==1)
            I.push_back(in[i]);
    }
}

float new_ele(int num,vector<int> test)
{
    int coun=0,flag;

    for(int i=0;i<test.size();i++)
    {
        flag = 1;
        for(int j=0;j<I.size();j++)
            if(test[i]==I[j])
            {
                flag=0;
                break;
            }
        if(flag==1)
            coun++;
    }
    if(coun==0)
        return INF;
    return num/coun;
}
int main()
{
int n,m,temp,flag=1,cost=0;

cout<<"Enter no. of elements in Universal set:";
cin>>n;

cout<<"Enter no. of subset sets:";
cin>>m;

for(int i=0;i<n;i++)
    U.push_back(i+1);
cout<<"Universal set: ";
for(int i=0;i<n;i++)
    cout<<U[i]<<"\t";
for(int i=0;i<m;i++)
{
    vector<int> T;
    cout<<"\nEnter elements of S"<<i+1<<"(Note Enter '0' to move to next set):";
    while(true)
    {
        cin>>temp;
        if(temp==0)
            break;
        T.push_back(temp);
    }
    cout<<"Enter the cost of S"<<i+1<<": ";
    cin>>temp;
    vector<int> t_v;
    t_v.push_back(temp);
    vector<vector<int>> TSC;
    TSC.push_back(T);
    TSC.push_back(t_v);
    S.push_back(TSC);
}
for(int i=0;i<S.size();i++)
{
    vector<int> T = S[i][0];
    vector<int> t_v = S[i][1];
    cout<<"\nSUBSET S"<<i+1<<": ";
    for(int j=0;j<T.size();j++)
        cout<<T[j]<<"\t";
    cout<<"\nCost: "<<t_v[0];
}
int c=1;
cout<<"\n";
while(m)
{
    vector<float> per_cost;

    for(int i=0;i<S.size();i++)
    {
        vector<int> T = S[i][0];
        vector<int> t_v = S[i][1];
        per_cost.push_back(new_ele(t_v[0],T));
    }
    int minElementIndex = std::min_element(per_cost.begin(),per_cost.end()) - per_cost.begin();
    long minElement = *std::min_element(per_cost.begin(), per_cost.end());
    vector<int> T = S[minElementIndex][0];
    vector<int> t_v = S[minElementIndex][1];
    visited_sets.push_back(minElementIndex+1);
    cost+=t_v[0];
    input_I(T);
    m--;
    cout<<"\nIteration "<<c<<": \n";
    for(int i=0;i<I.size();i++)
        cout<<I[i]<<"\t";
    if(I.size()==U.size())
        break;
    c++;
}
cout<<"\n\nTotal cost :"<<cost<<"\nSet cover subsets = {";
for(int i=0;i<visited_sets.size();i++)
{
    cout<<"S"<<visited_sets[i];
    if(i+1!=visited_sets.size())
        cout<<",";
}
cout<<"}";
return 0;
}
