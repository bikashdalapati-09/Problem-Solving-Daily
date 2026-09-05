class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        
        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;

        int maxLen = 0;
        int maxFreq = 0;

        while(j < n){
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);

            if((j - i + 1 - maxFreq) > k){
                mp[s[i]]--;
                i++;
            }

            if((j - i + 1 - maxFreq) <= k){
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        return maxLen;
    }
};