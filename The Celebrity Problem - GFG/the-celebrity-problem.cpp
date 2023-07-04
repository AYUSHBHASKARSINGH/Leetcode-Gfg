//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        int ans = -1;
        while(!st.empty()){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(M[a][b]==1 && M[b][a]==0){
                st.push(b);
            }
            else if(M[a][b] ==0 && M[b][a] == 1){
                st.push(a);
            }
            
            if(st.empty()){
                return -1;
            }
            
            if(st.size()==1){
                ans = st.top();
                break;
            }
        }
        // verify if ans is celeb or not 
        // its row m sarey zero and column me sarey 1 except [ans][ans]
        int flag=0;
        for(int i=0;i<n;i++){
            if(M[ans][i] != 0){
                flag=1;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=ans && M[i][ans] !=1){
                flag=1;
                break;
            }
        }
        
        if(flag){
            return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends