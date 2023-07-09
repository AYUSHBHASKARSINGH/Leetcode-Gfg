//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                arr[i] = 0;
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            int val = abs(arr[i]);
            if(val>=1 && val<=n){
                if(arr[val-1] > 0){
                    arr[val-1] *= -1;
                }
                else if(arr[val-1] == 0){
                  arr[val-1] = -1*(n+1);
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        
        int ans = -1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                ans = i+1;
                break;
            }
        }
        
        if(ans==-1){
            return n+1;
        }
        
        return ans;
        
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends