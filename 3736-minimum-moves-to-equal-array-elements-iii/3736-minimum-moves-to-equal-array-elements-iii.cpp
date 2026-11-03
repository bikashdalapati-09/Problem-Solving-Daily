class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;

        int maxi = *max_element(nums.begin(), nums.end());
        for(auto i : nums){
            ans += (maxi - i);
        }

        return ans;
    }
};