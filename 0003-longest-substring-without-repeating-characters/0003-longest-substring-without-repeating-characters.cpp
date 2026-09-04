class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;
        int duplicate = 0;
        int maxi = 0;

        while (j < n) {
            mp[s[j]]++;
            if (mp[s[j]] > 1) {
                duplicate++;
            }
            while (duplicate > 0) {
                if (mp[s[i]] > 1) {
                    duplicate--;
                }
                mp[s[i]]--;
                i++;
            }
            maxi = max(maxi, j - i + 1);
            j++;
        }
        return maxi;
    }
};