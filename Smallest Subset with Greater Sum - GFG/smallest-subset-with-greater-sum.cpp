//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        
        sort(arr.begin(),arr.end());
        long long sum1 = 0;
        for(int i=0;i<n;i++){
            sum1+=arr[i];
        }
        
        long long sum2 = 0;
        int j = n-1;
        
        int count = 0;
        while(true){
            sum2+=arr[j];
            sum1-= arr[j];
            j--;
            count++;
            if(sum2>sum1){
                break;
            }
        }
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends