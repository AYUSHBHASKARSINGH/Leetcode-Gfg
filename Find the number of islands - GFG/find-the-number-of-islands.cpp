//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void solve_dfs(int i,int j,vector<vector<char>>& grid,
        vector<vector<bool>> &vis,int row,int col){
            
            if(i>=row || j>=col || i<0 || j<0 || grid[i][j]=='0' || vis[i][j]==true){
                return;
            }
            
            vis[i][j] = true;
            
            // if(i+1 < row && grid[i+1][j]==1){
                solve_dfs(i+1,j,grid,vis,row,col);
            // }
            // if(i-1 > 0  && grid[i+1][j]==1){
                solve_dfs(i-1,j,grid,vis,row,col);
            // }
            // if(j+1 < col && grid[i+1][j]==1){
                solve_dfs(i,j+1,grid,vis,row,col);
            // }
            // if(j-1>0 && grid[i+1][j]==1){
                solve_dfs(i,j-1,grid,vis,row,col);
            // }
            // if(i+1 < row && j+1 < col && grid[i+1][j]==1){
                solve_dfs(i+1,j+1,grid,vis,row,col);
            // }
            // if(i+1 < row && j-1>0 && grid[i+1][j]==1){
                solve_dfs(i+1,j-1,grid,vis,row,col);
            // }
            // if(i-1 >0 && j+1<col && grid[i+1][j]==1){
                solve_dfs(i-1,j+1,grid,vis,row,col);
            // }
            // if(i-1 >0 && j-1 >0 && grid[i+1][j]==1){
                solve_dfs(i-1,j-1,grid,vis,row,col);
            // }
        }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        // cout<<row<<" "<<col<<endl;
        vector<vector<bool>> vis(row,vector<bool> (col,false));
        
        int count = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    solve_dfs(i,j,grid,vis,row,col);
                    count++;
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends