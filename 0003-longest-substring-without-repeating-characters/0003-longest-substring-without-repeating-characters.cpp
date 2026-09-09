class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int i = 0;
        int j = 0;

        unordered_map<char, int>mp;
        int duplicate = 0;
        int maxi = 0;

        while(j < n){
            mp[s[j]]++;
            if(mp[s[j]] > 1){
                duplicate++;
            }
            while(duplicate > 0){
                mp[s[i]]--;
                if(mp[s[i]] == 1){
                    duplicate--;
                }
                i++;
            }
            if(duplicate == 0){
                maxi = max(maxi, j-i+1);
            }
            j++;
        }
        return maxi;
    }
};