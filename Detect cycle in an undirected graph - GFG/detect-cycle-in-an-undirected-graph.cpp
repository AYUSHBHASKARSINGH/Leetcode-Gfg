//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,false);
        vector<int> parent(V,-1);
        bool ans = false;
        
        for(int i=0;i<V;i++){
            queue<int> q;
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = -1;
                while(!q.empty()){
                    int front = q.front();
                    // visited[front] = true;
                    q.pop();
                    for(int i=0;i<adj[front].size();i++){
                        if(parent[front] != adj[front][i] && visited[adj[front][i]]==true){
                            return true;
                        }
                        
                        else if(!visited[adj[front][i]]){
                            q.push(adj[front][i]);
                            visited[adj[front][i]] = true;
                            parent[adj[front][i]] = front;
                        }
                        
                    }
                    
                }
                
            }
        }
        
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends