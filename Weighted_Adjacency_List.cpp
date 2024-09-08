#include<bits/stdc++.h>
using namespace std;

int main()
{
    // for adjacency list we store u -> (v, w) & v -> (u, w)
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        pair<int, int> pi1;
        pair<int, int> pi2;

        pi1.first = v;
        pi1.second = w;
        pi2.first = u;
        pi2.second = w;

        adj[u].push_back(pi1);
        adj[v].push_back(pi2);

    }
    
    return 0;
}
