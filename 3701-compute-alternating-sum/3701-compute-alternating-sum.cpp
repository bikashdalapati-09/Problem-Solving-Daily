class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        bool flag = true;
        int ans = 0;
        
        for(auto num : nums){
            ans += (flag ? num : -num);
            flag = !flag;
        }
        return ans;
    }
};