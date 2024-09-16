#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]) 
{
    vis[src] = 1; 

    // store <source node, parent node>
    queue<pair<int, int>> q;
    q.push({src, -1}); 

    while(!q.empty()) 
    {
        int node = q.front().first; 
        int parent = q.front().second; 
        q.pop(); 

        for(auto adjacentNode: adj[node]) 
        {
            if(!vis[adjacentNode]) 
            {
                vis[adjacentNode] = 1; 
                q.push({adjacentNode, node}); 
            }
            else if(parent != adjacentNode) // if adjacent node is visited and is not it's own parent node
            {
                return true; // yes it is a cycle
            }
        }
    }
    return false; 
}

bool isCycle(int V, vector<int> adj[]) // whhen you check for disconnected components
{
    int vis[V] = {0};
    for(int i = 0;i<V;i++) 
    {
        if(!vis[i]) 
        {
            if(detect(i, adj, vis)) return true; 
        }
    }
    return false; 
}

// tc = O(N + 2E)
// sc = O(N)

int main() 
{
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}