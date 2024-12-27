#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;

    public:
        DisjointSet(int n) // constructor which helps w initialization
        {
            rank.resize(n + 1, 0); // n + 1 for 1 based indexing
            parent.resize(n + 1);

            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int findUltimateParent(int node) 
        {
            if(node == parent[node]) return node;
            else return parent[node] = findUltimateParent(parent[node]); // with path compression you store the ultimate parent in every level parent node
            // else return findUltimateParent(parent[node]); // without path compression
        }

        void unionByRank(int u, int v)
        {
            int ult_par_u = findUltimateParent(u), ult_par_v = findUltimateParent(v);

            if(ult_par_u == ult_par_v) return;
            
            if(rank[ult_par_u] < rank[ult_par_v]) parent[ult_par_u] = ult_par_v;
            else if(rank[ult_par_u] > rank[ult_par_v]) parent[ult_par_v] = ult_par_u;
            else
            {
                parent[ult_par_v] = ult_par_u;
                rank[ult_par_u]++;
                // OR
                // parent[ult_par_u] = ult_par_v;
                // rank[ult_par_v]++;
            }
        }

};

int main()
{
    
    return 0;
}