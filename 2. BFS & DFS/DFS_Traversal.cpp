#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> & ls)
{
    vis[node] =1;
    ls.push_back(node);
    for(auto it : adj[node])
    {
        if(!vis[it]) dfs(it, adj, vis, ls);
    }
}
int main()
{
    // Depth First Traversal of a graph
    // Assume that the starting node of the graph is 1, i.e, 1 based graph
    // 

    // Requirements :
    // 1) Visited array
    // 2) Call a recursion to visit neighbours of current node
    // 3) Neighbours stored in adjacency list

    int n;
    vector<int> adj[n];

    int vis[n] = {0};
    int start = 0;
    vector<int> ls;

    dfs(start, adj, vis, ls);

    // Space complexity -> O(n)
    // Time complexity -> O(2 * E + n) (for undirected)

    return 0;
}
