class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int neg = 0;
        for (auto &row : grid) {
            
            int l = 0;
            int r = row.size() - 1;

            while(l <= r){
                int mid = l + (r - l) / 2;
                if(row[mid] >= 0){
                    l = mid + 1;
                }
                else{
                    r = mid-1;
                }
            }
            neg += (row.size() - l);
        }
        return neg;
    }
};
