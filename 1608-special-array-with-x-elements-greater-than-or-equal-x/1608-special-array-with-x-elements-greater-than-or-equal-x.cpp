class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = -1;

        for(int i = 0;i <= maxi;i++){
            int count = 0;
            for(int j = 0;j < n;j++){
                if(nums[j] >= i){
                    count++;
                }
            }
            if(count == i){
                ans = i;
            }
        }
        return ans;
    }
};