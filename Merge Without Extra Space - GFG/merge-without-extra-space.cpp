//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    private:
        void swap_g(long long arr1[], long long arr2[],long long i,long long j){
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
        }
        
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            long long gap = ((m+n)/2) + (m+n)%2;
            while(gap>0){
                long long left = 0;
                long long right = left+gap;
                
                while(right<(m+n)){
                    
                    if(left<n && right>=n){
                        swap_g(arr1,arr2,left,right-n);
                    }
                    else if(left>=n){
                        swap_g(arr2,arr2,left-n,right-n);
                    }
                    else{
                        swap_g(arr1,arr1,left,right);
                    }
                    left++;
                    right++;
                }
                
                if(gap==1){
                    break;
                }
                
                gap = (gap/2) + (gap%2);
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends