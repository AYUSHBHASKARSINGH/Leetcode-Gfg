//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool vis[V];
        for(int i=0;i<V;i++){
            vis[i] = false;
        }
    
        
        vector<int> ans;
        
        
        // For visiting all nodes in case of dsiconnected graph
        // for(int i=0;i<V;i++){
            // if(!vis[i]){
                queue<int> q;
                q.push(0);
                vis[0] = true;
                while(!q.empty()){
                    int front_node = q.front();
                    q.pop();
                    // vis[front_node] = true;
                    ans.push_back(front_node);
                    
                    for(int j=0;j<adj[front_node].size();j++){
                        if(!vis[adj[front_node][j]]){
                            q.push(adj[front_node][j]);
                            vis[adj[front_node][j]]= true;
                        }
                    }
                }
            // }
        // }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends