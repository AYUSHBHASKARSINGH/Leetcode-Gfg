//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    
  public:
    void dfs(vector<int> &ans,vector<int> adj[],vector<bool> &visited,int node){
            ans.push_back(node);
            visited[node] = true;
             
            // HAR CONNECTED NODE K LIYE RECURSIVE CALL
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    dfs(ans,adj,visited,adj[node][i]);
                }
            }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // vector<bool> vis(V,false);
        // stack<int> st;
        // vector<int> ans;
        // st.push(0);
        // while(!st.empty()){
        //     int top = st.top();
        //     st.pop();
            
        //     if(!vis[top]){
        //         ans.push_back(top);
        //         vis[top] = true;
        //     }
            
        //     for(int i=adj[top].size()-1;i>=0;i--){
        //         if(!vis[adj[top][i]]){
        //             st.push(adj[top][i]);
        //         }
        //     }
        // }
        
        // return ans;
        
        
        
        // -----USING RECURRSION
        
        vector<int> ans;
        vector<bool> visited(V,false);
        
        dfs(ans,adj,visited,0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends