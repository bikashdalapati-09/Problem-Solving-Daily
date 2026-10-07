class Solution {
public:
    int n;
    unordered_set<string> st;

    void solve(string& s, int i, string& curr, int count) {
        if (count < 0) {
            return;
        }

        if (i == n) {
            if (count == 0) {
                st.insert(curr);
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            curr.push_back(s[i]);
            solve(s, i + 1, curr, count);
            curr.pop_back();
            return;
        }

        curr.push_back(s[i]);

        solve(s, i + 1, curr, count + (s[i] == '(' ? 1 : -1));

        curr.pop_back();

        solve(s, i + 1, curr, count);
    }

    vector<string> removeInvalidParentheses(string s) {
        n = s.size();

        string curr = "";

        solve(s, 0, curr, 0);

        vector<string> ans;
        int maxlen = 0;

        for (auto i : st) {
            if (i.size() > maxlen) {
                maxlen = i.size();
                ans.clear();
            }
            if (i.size() == maxlen) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};