//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void recur_permu(vector<string> &ans,string S, string ds, vector<int> freq){
            
            if(ds.length() == S.length()){
                ans.push_back(ds);
                return;
            }
            
            for(int i=0;i<S.length();i++){
                if(!freq[i]){
                    freq[i] = true;
                    ds = ds + S[i];
                    // cout<<ds<<endl;
                    recur_permu(ans,S,ds,freq);
                    ds.erase(ds.length()-1);
                    freq[i] = false;
                }
            }
        }
        
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    
		    vector<string> ans;
		    string ds;
		    vector<int> freq(S.length(),false);
		    
		    recur_permu(ans,S,ds,freq);
		    set<string> st;
		    for(int i=0;i<ans.size();i++){
		        st.insert(ans[i]);
		    }
		    
		    vector<string> temp;
		    
		    for(auto it: st){
		        temp.push_back(it);
		    }
		    
		    return temp;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends