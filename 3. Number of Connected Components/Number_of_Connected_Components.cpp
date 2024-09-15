#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLs[], int vis[]) {
    // mark the node as visited
    vis[node] = 1; 
    for(auto it: adjLs[node]) 
    {
        if(!vis[it]) // if not visited, then iterate to the next node and apply dfs
        {
            dfs(it, adjLs, vis); 
        }
    }
}

int main()
{
    int V;
    vector<int> adjLs[V];
    int vis[V];

    for(int i = 0; i < V; i++) vis[i] = 0;
    
    int cnt = 0; 
    for(int i = 0;i<V;i++) 
    {
        if(!vis[i]) {
            cnt++;
            dfs(i, adjLs, vis); 
        }
    }

    cout<<cnt<<endl;

    return 0;
}
