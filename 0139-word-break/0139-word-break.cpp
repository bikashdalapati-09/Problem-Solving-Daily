class Solution {
public:
    bool solve(int idx, string s, unordered_set<string>& st, vector<int> &dp) {
        if (idx >= s.size()) {
            return true;
        }

        if (st.find(s) != st.end()) {
            return true;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        for (int len = 1; len <= s.size(); len++) {
            string temp = s.substr(idx, len);
            if (st.find(temp) != st.end() && solve(idx + len, s, st, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;

        for (auto i : wordDict) {
            st.insert(i);
        }
        vector<int> dp(s.size(), -1);
        return solve(0, s, st, dp);
    }
};