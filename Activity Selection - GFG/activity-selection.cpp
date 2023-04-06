//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int> x,pair<int,int> y) {
            if (x.second != y.second) {
                return x.second < y.second;
            }
     
            return x.first < y.first;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back(make_pair(start[i],end[i]));
        }
        
        sort(vec.begin(),vec.end(),comp);
        
        // for(int i=0;i<n;i++){
        //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
        // }
        
        int count=1;
        int i=0,j=1;
        
        while(i<n && j<n){
            if(vec[i].second<vec[j].first){
                i=j;
                j++;
                count++;
                // cout<<"hh"<<endl;
            }
            else{
                j++;
            }
        }
        
        // int flag=0;
        // if(vec[n-1].first>vec[n-2].second){
        //     count++;
        //     flag=1;
        // }
        
        
        
        return count;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends