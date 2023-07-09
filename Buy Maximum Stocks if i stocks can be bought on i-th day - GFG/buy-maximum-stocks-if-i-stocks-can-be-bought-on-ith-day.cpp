//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back(make_pair(price[i],i+1));
        }
        
        sort(vec.begin(),vec.end());
        int count = 0;
        for(int i=0;i<n;i++){
            if(k>0){
                if(k > (vec[i].first*vec[i].second)){
                    count+= vec[i].second;
                    k -= (vec[i].first*vec[i].second);
                }
                else{
                    if(k<=0){
                        break;
                    }
                    else{
                        int tt = k/vec[i].first;
                        if(tt<=vec[i].second){
                            count+=tt;
                            k-=(tt*vec[i].first);
                        }
                        else{
                            count+=(tt-vec[i].second);
                            k-=(vec[i].first*(tt-vec[i].second));
                        }
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
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends