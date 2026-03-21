class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int, int>> st;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(abs(nums[i]-nums[j]) == k){
                    // cout << nums[i] << " " << nums[j] << endl;
                    (nums[i] > nums[j]) ? st.insert({nums[i], nums[j]}) : st.insert({nums[j], nums[i]});
                }
            }
        }
        return st.size();
    }
};