//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int count=0;
        int sum_temp=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0'){
                sum_temp+= -1;
            }
            if(str[i]=='1'){
                sum_temp += 1;
            }
            
            if(sum_temp==0){
                count++;
            }
        }
        
        if(count!=0 && sum_temp == 0){
            return count;
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends