//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{  
private:
    int binary_s(vector<vector<int>> &matrix, int r, int c,int key){
        auto it = upper_bound(matrix[r].begin(),matrix[r].end(),key)- matrix[r].begin();
        return it;
    }
    
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here    
        int size = R*C;
        int half = size/2;     //size/2 dono trf of median
        
        int l = 1,r = 2000;
        while(l<=r){
            int mid = (l+r)/2;
            int temp = 0;
            for(int i=0;i<R;i++){
                temp+= binary_s(matrix,i,C,mid);
            }
            
            if(temp>half){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        
        return l;
        
        
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends