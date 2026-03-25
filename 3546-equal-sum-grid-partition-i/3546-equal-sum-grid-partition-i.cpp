class Solution {
public:
    using ll = long long;
    
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        ll totalSum = 0;
        
        for(auto nums : grid){
            for(auto num : nums){
                totalSum += num;
            }
        }

        if(totalSum % 2 != 0){
            return false;
        }
        ll half = totalSum / 2;


        // Row wise --->
        ll rowSum = 0;
        for(int i = 0;i < m-1;i++){
            for(int j = 0;j < n;j++){
                rowSum += grid[i][j];
            }
            if(rowSum == half){
                return true;
            }
        }

        // col wise
        ll colSum = 0;
        for(int j = 0;j < n-1;j++){
            for(int i = 0;i < m;i++){
                colSum += grid[i][j];
            }
            if(colSum == half){
                return true;
            }
        }
        return false;
    }
};