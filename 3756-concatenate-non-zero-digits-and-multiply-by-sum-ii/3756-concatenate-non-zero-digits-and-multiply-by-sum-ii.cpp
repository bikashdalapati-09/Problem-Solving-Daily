class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<long long> pref(s.size() + 1, 0);
        vector<long long> dpref(s.size() + 1, 0);
        vector<int> ans;
        vector<int> dcnt(s.size() + 1, 0);
        vector<long long> pow10(s.size() + 1);
        pow10[0] = 1;

        for (int i = 1; i <= s.size(); i++)
            pow10[i] = (pow10[i - 1] * 10) % mod;
        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';
            dpref[i + 1] = dpref[i] + d;
            if (d == 0) {
                pref[i + 1] = pref[i];
                dcnt[i + 1] = dcnt[i];
            } else {
                dcnt[i + 1] = dcnt[i] + 1;
                pref[i + 1] = (pref[i] * 10 + d) % mod;
            }
        }
        for (auto i : queries) {
            int m = dpref[i[1] + 1] - dpref[i[0]];
            int a = pref[i[1] + 1];
            int b = pref[i[0]];
            int cnt = dcnt[i[1] + 1] - dcnt[i[0]];
            long long x =
                (pref[i[1] + 1] - pref[i[0]] * pow10[cnt] % mod + mod) % mod;
            ans.push_back((x * m) % mod);
        }
        return ans;
    }
};