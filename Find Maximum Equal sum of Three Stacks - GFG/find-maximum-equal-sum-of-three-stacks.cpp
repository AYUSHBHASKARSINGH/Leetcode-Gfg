//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &st1,vector<int> &st2,vector<int> &st3){
        int sum1=0,sum2=0,sum3=0;
        for(int i=0;i<n1;i++){
            sum1+=st1[i];
        }
        for(int i=0;i<n2;i++){
            sum2+=st2[i];
        }
        for(int i=0;i<n3;i++){
            sum3+=st3[i];
        }
        
        int i=0,j=0,k=0;
        int ans = 0;
        while(true){
            int maxi = max(sum1,max(sum2,sum3));
            
            if(sum1 == sum2 && sum2 == sum3){
                ans = sum1;
                break;
            }
            
            if(i>=n1 && j>=n2 && k>=n3){
                break;
            }
            
            if(i<n1 && sum1 == maxi){
                sum1-=st1[i];
                i++;
            }
            
            else if(j<n2 && sum2 == maxi){
                sum2-=st2[j];
                j++;
            }
            else if(k<n3 && sum3==maxi){
                sum3-=st3[k];
                k++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends