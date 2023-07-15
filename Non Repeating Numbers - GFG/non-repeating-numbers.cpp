//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.

        int xora = 0;        
        for(int i=0;i<nums.size();i++){
            xora = xora^nums[i];
        }
        
        int count=0;
        while(xora>0){
            if(xora & 1){
                break;
            }
            count++;
            xora = xora>>1;
        }
        
        int mask = 1<<count;
        
        int xor1=0,xor2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & mask){
                xor1 = xor1^nums[i];
            }
            else{
                xor2 = xor2^nums[i];
            }
        }
        
        vector<int> ans;
        ans.push_back(xor1);
        ans.push_back(xor2);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends