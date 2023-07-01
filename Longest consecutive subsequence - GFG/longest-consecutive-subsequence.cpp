//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_map<int,int> mp;
      for(int i=0;i<n;i++){
          mp[arr[i]]++;
      }
        
        int ans =1;
        for(int i=0;i<n;i++){
            int temp = 1;
          if(mp[arr[i]-1]>=1){
            temp++;
            int j = arr[i]+1;
            while(mp[j]>=1){
                temp++;
                j++;
            }
            ans = max(temp,ans);
          }
      }
      return ans;
      
      
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends