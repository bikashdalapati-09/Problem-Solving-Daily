class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto& i : nums){
            mp[i]++;
        }

        for(auto [key, val] : mp){
            if(val == 1){
                return key;
            }
        }
        return 0;
    }
};