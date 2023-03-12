//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code 
        vector<int> vec;
        int a1;
        if(N%(K+1)==0){
            a1 = N/(K+1);
        }
        else{
            a1 = (N/(K+1))+1;
        }
        // vec.push_back(a1);
        
        
        
        sort(candies,candies+N);
        int ans = 0;
        int a2 = 0;

        for(int i=0;i<a1;i++){
            ans+=candies[i];
        }
        for(int i=N-1;i>=(N-a1);i--){
            a2+=candies[i];
        }
        
        vec.push_back(ans);
        vec.push_back(a2);
        
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends