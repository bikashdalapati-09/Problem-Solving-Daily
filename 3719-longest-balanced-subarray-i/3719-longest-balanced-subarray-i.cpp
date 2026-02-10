class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxi = 0;
        for(int i = 0;i < nums.size();i++){
            unordered_set<int> st1, st2;
            for(int j = i;j < nums.size();j++){
                if(nums[j] & 1){
                    st1.insert(nums[j]);
                }else{
                    st2.insert(nums[j]);
                }
                if(st1.size() == st2.size()){
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};