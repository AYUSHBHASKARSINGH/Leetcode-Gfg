//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
bool comparator(Item a,Item b){
    float a1 = a.value;
    float a2 = a.weight;
    float b1 = b.value;
    float b2 = b.weight;
    
    return ((a1/a2) > (b1/b2));
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comparator);
        
        double ans = 0;
        for(int i=0;i<n;i++){
            if(W!=0){
                if(arr[i].weight < W){
                    ans+=arr[i].value;
                    W-=arr[i].weight;
                }
                else{
                    // cout<<"ASdad"<<endl;
                    float tt = arr[i].weight;
                    double temp = W/tt;
                    // cout<<temp<<endl;
                    ans+=(arr[i].value * temp); 
                    W = 0;
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends