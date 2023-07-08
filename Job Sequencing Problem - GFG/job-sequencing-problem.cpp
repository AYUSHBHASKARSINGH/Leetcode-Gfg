//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

// class Solution 
// {

//     public:
//     static bool comparison(Job a,Job b){
//         return a.profit>b.profit;
//     }

//     //Function to find the maximum profit and the number of jobs done.
//     vector<int> JobScheduling(Job arr[], int n) 
//     { 
//         // your code here
//         sort(arr,arr+n,comparison);
//         int maxi = arr[0].dead;
        
//         int brr[maxi+1];
//         for(int i=0;i<=maxi;i++){
//             brr[i] = -1;
//         }
//         int sum=0;
//         int count=0;
        
//         for(int i=0;i<n;i++){
//             // if(brr[arr[i].dead]==-1){
//             //     brr[arr[i].dead-1] = arr[i].id;
//             //     sum+=arr[i].profit;
//             //     count++;
//             // }
//             // else{
//                 for(int j=arr[i].dead;j>0;j--){
//                     if(brr[j]==-1){
//                         brr[j] = i;
//                         sum+=arr[i].profit;
//                         count++;
//                         break;
//                     }
//                 }
//             // }
//         }
//         vector<int> vec;
//         vec.push_back(count);
//         vec.push_back(sum);
        
//         return vec;
//     } 
// };


class Solution 
{

    public:
    static bool comparison(Job a,Job b){
        return a.profit>b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comparison);
        int maxi= -1;
        int sum=0;
        int count = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i].dead);
        }
        
        int brr[maxi];
        for(int i=0;i<maxi;i++){
            brr[i] = -1;
        }
        
        for(int i=0;i<n;i++){
            for(int j = arr[i].dead-1;j>=0;j--){
                if(brr[j] == -1){
                    brr[j] = 1;
                    sum+=arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        
        vector<int> vec;
        vec.push_back(count);
        vec.push_back(sum);
        
        return vec;
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends