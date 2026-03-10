class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = INT_MIN;

        for(auto acc : accounts){
            int total = 0;
            for(auto i : acc){
                total += i;
            }
            maxi = max(maxi, total);
        }
        return maxi;
    }
};