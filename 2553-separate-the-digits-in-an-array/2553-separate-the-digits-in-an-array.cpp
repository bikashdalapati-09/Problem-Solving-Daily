class Solution {
public:
    void solve(int num, vector<int>& ans) {
        string s = to_string(num);
        for (auto i : s) {
            ans.push_back(i - '0');
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto num : nums) {
            solve(num, ans);
        }
        return ans;
    }
};