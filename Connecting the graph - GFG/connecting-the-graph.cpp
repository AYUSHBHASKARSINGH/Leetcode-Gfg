//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    vector<int> rank,parent,size;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }


    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        // PATH COMPRESSION--
        return parent[node] = findUltimateParent(parent[node]);
    }

// UNION BY RANK
    void UnionByRank(int u,int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v){
            return;
        }
        else{
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    }

    void UnionBySize(int u,int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if(ulp_u == ulp_v){
            return;
        }
        else{
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = parent[ulp_v];
                size[ulp_v] +=size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        // if()
        
        
        DisjointSet ds(n);
        int extra_edges = 0;
        for(int i=0;i<edge.size();i++){
            if(ds.findUltimateParent(edge[i][0]) == ds.findUltimateParent(edge[i][1])){
                extra_edges++;
            }
            ds.UnionBySize(edge[i][0],edge[i][1]);
        }
        
        int count = -1;
        for(int i=0;i<n;i++){
            if(ds.findUltimateParent(i) == i){
                count++;
            }
        }
        
        if(extra_edges>=count){
            return count;
        }
        
        else{
            return -1;
        }

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends