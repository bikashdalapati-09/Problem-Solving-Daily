class Solution {
public:
    bool balance(unordered_map<char, int>& mp) {
        if (mp.empty())
            return true;

        int freq = mp.begin()->second;
        for (const auto& it : mp) {
            if (it.second != freq) {
                return false;
            }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                if (balance(mp)) {
                    maxi = max(maxi, j - i + 1);
                }
            }
            mp.clear();
        }
        return maxi;
    }
};