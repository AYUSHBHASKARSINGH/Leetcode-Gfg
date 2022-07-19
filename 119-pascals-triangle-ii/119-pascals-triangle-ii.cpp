class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> arr;
        
        arr.push_back({1});
        
            
        for(int i=1;i<=rowIndex;i++){
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
        
        
        return arr[rowIndex];
    }
};