//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
private:
    int helper(vector<vector<int> > arr, int n, int m){
        int low = 0;
        int high = m-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[n][mid]==0){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return m-low;
    }
    
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int maxi = 0;
	    int ind = -1;
	   // for(int i=0;i<n;i++){
	   //     auto temp = upper_bound(arr[i].begin(),arr[i].end(),0) - arr[i].begin();
	   //     int yy = m-temp;
	        
	   //     if(yy>maxi){
	   //         maxi = yy;
	   //         ind = i;
	   //     }
	   // }
	   // return ind;
	   
	   
	   //WITHOUT UPPER BOUND
	   
	   for(int i=0;i<n;i++){
	       int temp = helper(arr,i,m);
	       //cout<<"ans-->"<<temp<<endl;
	       if(temp>maxi){
	           maxi = temp;
	           ind = i;
	       }
	   }
	   return ind;
	   
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends