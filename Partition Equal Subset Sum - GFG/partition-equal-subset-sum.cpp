//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int ind,int arr[],int n,int sum,int curr){
        if(sum==curr){
            // cout<<curr<<endl;
            return 1;
        }
        
        if(ind>=n){
            return 0;
        }
        
        if(curr>sum){
            // cout<<curr<<endl;
            return 0;
        }

        int a = solve(ind+1,arr,n,sum,curr+arr[ind]);
        if(!a){
            // curr-=arr[ind];
            int b = solve(ind+1,arr,n,sum,curr);
            if(!b){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
        
        return 0;
    }
    
    
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum1 = 0;
        for(int i=0;i<n;i++){
            sum1+=arr[i];
        }
        if(sum1%2 == 1){
            return 0;
        }
        
        int sum = sum1/2;
        int curr=0;
        int ind=0;
        return solve(ind,arr,n,sum,curr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends