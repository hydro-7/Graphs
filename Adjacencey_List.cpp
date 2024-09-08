#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;

        // undirected graphs :
        adj[u].push_back(v);
        adj[v].push_back(u);

        // directed graphs :
        // adj[u].push_back(v);
    }


    // Takes n^2 space & n time

    return 0;
}
