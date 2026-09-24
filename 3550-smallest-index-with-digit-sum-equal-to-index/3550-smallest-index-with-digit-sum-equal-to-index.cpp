class Solution {
public:
    int check(string s){
        int ans = 0;
        for(auto ch : s){
            ans += (ch - '0');
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){

            if(i == check(to_string(nums[i]))){
                return i;
            }
        }
        return -1;
    }
};