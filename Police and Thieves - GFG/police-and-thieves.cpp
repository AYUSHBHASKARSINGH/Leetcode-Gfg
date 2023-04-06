//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        int count =0;
        for(int i=0;i<n;i++){
            if(arr[i]=='P'){
                for(int j=i-k ; j<=i+k;j++){
                    if(j<0){
                        continue;
                    }
                    if(j>=n){
                        break;
                    }
                    
                    if(arr[j]=='T'){
                        count++;
                        arr[j] = 'C';
                        break;
                    }
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends