#include<bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &stk)
{
    vis[node] = 1;
    for(auto it : adj[node])
    {
        int v = it.first;
        if(!vis[v]) topoSort(v, adj, vis, stk);
    }

    stk.push(node);
}

vector<int> shortestPath(int N, int M, vector<int> edges[])
{
    vector<pair<int, int>> adj[N];

    for(int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // Topo Sort
    int vis[N] = {0};
    stack<int> stk;

    for(int i = 0; i < N; i++)
    {
        if(!vis[i]) topoSort(i, adj, vis, stk);
    }

    vector<int> dist(N);
    for(int i = 0; i < N; i++) dist[i] = INT_MAX; // or 1e9

    dist[0] = 0; // source node = 0

    while(!stk.empty())
    {
        int node = stk.top();
        stk.pop();

        for(auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    return dist;
}

int main()
{
    
    return 0;
}