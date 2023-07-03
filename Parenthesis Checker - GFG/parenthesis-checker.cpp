//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        unordered_map<char,int> mp;
        mp['{'] = -1;
        mp['('] = -2;
        mp['['] = -3;
        mp['}'] = 1;
        mp[')'] = 2;
        mp[']'] = 3;
        
        stack<char> st;
        for(int i=0;i<x.length();i++){
           if(mp[x[i]] < 0){
               st.push(x[i]);
           }
          else{
                if(st.empty()){
                    return false;
                }
                
                if(mp[st.top()] + mp[x[i]] == 0){
                    st.pop();
                }
                else{
                    return false;
                }
          }
        }
        
        if(st.empty()){
            return true;
        }
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends