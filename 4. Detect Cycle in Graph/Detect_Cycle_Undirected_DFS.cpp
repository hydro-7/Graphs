#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[], vector<int> adj[]) 
{
    vis[node] = 1;
    for(auto adjNode : adj[node])
    {
        if(!vis[adjNode])
        {
            if(dfs(adjNode, node, vis, adj) == true) return true;
        }
        else if(adjNode != parent) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) 
{
    int vis[V] = {0}; 
    // for graph with connected components 
    for(int i = 0; i < V; i++) 
    {
        if(!vis[i]) 
        {
            if(dfs(i, -1, vis, adj) == true) return true; 
        }
    }
    return false; 
}

// tc = O(N + 2E)
// sc = O(N)

int main() 
{
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}