//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool is_possible(bool graph[101][101],int j,int node,int n,
        vector<int> &color){
            
            for(int k=0;k<n;k++){
                if(graph[node][k]==1){
                    if(color[k] == j){
                        return false;
                    }
                }
            }
            
            return true;
    }
    
    
    
    bool solve(bool graph[101][101],int m,int n,vector<int> &color){
                
            for(int i=0;i<n;i++){
                if(color[i]==0){
                    for(int j=1;j<=m;j++){
                        if(is_possible(graph,j,i,n,color)){
                            color[i] = j;
                            bool solvable_agey = solve(graph,m,n,color);
                            if(solvable_agey){
                                return true;
                            }
                            else{
                                // BACKTRACK;
                                color[i] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
            
            return true;
    }
    
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n,0);
        
        // vector<vector<int>> color(n,vector<int> (n,0));
        bool temp = solve(graph,m,n,color);

        return temp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends