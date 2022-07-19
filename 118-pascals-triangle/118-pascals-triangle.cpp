class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> arr;
        
        arr.push_back({1});
        // arr.push_back({1},{1,1});
            
        for(int i=1;i<numRows;i++){
            vector<int> t1;
            for(int j=0;j<=i;j++){
                if(j==0|| j==i){
                    t1.push_back(1);
                }
                else{
                    t1.push_back(arr[i-1][j]+arr[i-1][j-1]);
                }
                
            }
            
            arr.push_back(t1);
            t1.clear();
        }
        
        return arr;
    }
};