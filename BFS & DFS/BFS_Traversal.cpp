#include<bits/stdc++.h>
using namespace std;

int main()
{
    // aka level wise traversal
    // Requirements : 
    // 1) Queue
    // 2) Visited Array
    // Assuming a 0 based indexing graph 

    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1]; // adjacency list

    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while(!q.size()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    // return bfs;

    // Space complexity -> O(n)
    // Time complexity -> O(n + 2E)

    return 0;
}
