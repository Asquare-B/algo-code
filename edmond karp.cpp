#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
using namespace std;
#define V 6
bool bfs(int rGraph[V][V], int s, int t, int parent[]){
    bool visited[V];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
int edmond(int graph[V][V], int s, int t){
    int u, v;
    int rGraph[V][V];
    cout<<"Augumented Paths:\n";
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    int parent[V];
    int path[V],i=0;
    path[0]=t;
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (i=1,v = t; v != s; v = parent[v],i++) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
            path[i]=u;
        }
        for(int j=i-1;j>=0;j--){
            cout<<path[j];
            if(j !=0)
                cout<<"-->";
            }
            cout<<"\n";
            for (v = t; v != s; v = parent[v]) {
                u = parent[v];
                rGraph[u][v] -= path_flow;
                rGraph[v][u] += path_flow;
            }
            max_flow += path_flow;
        }
        return max_flow;
}
int main(){
    int graph[V][V]={
        {0,16,13,0,0,0},
        {0,0,10,12,0,0},
        {0,4,0,0,14,0},
        {0,0,9,0,0,20},
        {0,0,0,7,0,4},
        {0,0,0,0,0,0}
    };
    int maxflow;
    cout<<"AALAP BHAKTA -- 19MIC0122\n";
    cout<<"\n";
    maxflow=edmond(graph,0,5);
    cout<<"\n";
    cout<<"The maximum possible flow : "<<maxflow;
    return 0;
}
