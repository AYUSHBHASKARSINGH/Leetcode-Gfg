//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    
    bool valid_insert(int val,int grid[N][N],int row,
        int col){
            
            for(int i=0;i<9;i++){
                if(grid[i][col]==val){
                    return false;
                }
            }
            
            for(int j=0;j<9;j++){
                if(grid[row][j] == val){
                    return false;
                }
            }
            
            int temp1 = col - (col%3);
            int temp2 = row - (row%3);
            
            for(int i=temp2;i<temp2+3;i++){
                for(int j=temp1;j<temp1+3;j++){
                    if(grid[i][j]==val){
                        return false;
                    }
                }
            }
            
            return true;
            
    }
    
    
    
    bool solve(int grid[N][N]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                // check if occupied or empty
                if(grid[i][j] == 0){
                    
                    for(int val=1;val<=9;val++){
                        
                        if(valid_insert(val,grid,i,j)){
                            grid[i][j] = val;
                            bool solvable = solve(grid);
                            if(solvable){
                                return true;
                            }
                            else{
                                grid[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }   
    
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        bool temp = solve(grid);
        return temp;
    }
    
    
    
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends