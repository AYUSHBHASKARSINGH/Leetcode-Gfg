//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void solve(vector<string> &ans,vector<vector<int>> m,int n,int i,
        int j,string &str,vector<vector<int>> &visited){
        if(i>=n || i<0 || j>=n || j<0){
            // str.pop_back();
            return;
        }
        if(i==n-1 && j==n-1){
            ans.push_back(str);
            return;
        }
        
        
        if(i+1<n && m[i+1][j]==1 && visited[i][j]==0){
            visited[i][j]=1;
            string temp = "D";
            str = str+temp;
            solve(ans,m,n,i+1,j,str,visited);
            // visited[i][j]==0;
            str.pop_back();
            visited[i][j]=0;
        }
        
        if(j-1>=0 && m[i][j-1]==1 && visited[i][j]==0){
            visited[i][j]=1;
            string temp = "L";
            str = str+temp;
            solve(ans,m,n,i,j-1,str,visited);
            str.pop_back();
            visited[i][j]=0;
        }
        
        if(j+1<n && m[i][j+1]==1 && visited[i][j]==0){
            visited[i][j]=1;
            string temp = "R";
            str = str+temp;
            solve(ans,m,n,i,j+1,str,visited);
            str.pop_back();
            visited[i][j]=0;
        }
        
        if(i-1>=0 && m[i-1][j]==1 && visited[i][j]==0){
            visited[i][j]=1;
            string temp = "U";
            str = str+temp;
            solve(ans,m,n,i-1,j,str,visited);
            str.pop_back();
            visited[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string str = "";
        
        vector<vector<int>> visited(n,vector<int> (n,0));
        if(m[0][0]==0){
            ans.push_back(to_string(-1));
            return ans;
        }
        
        solve(ans,m,n,0,0,str,visited);
        
        if(ans.size()==0){
            string temp = "-1";
            ans.push_back(temp);
        }
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends