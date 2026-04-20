class Solution {
public: 
    bool solve(string &s, int l, int r){
        if(l >= r) 
            return 1;

        if(s[l] == s[r]) {
            return solve(s, l+1, r-1);
        }

        return false;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxlen = INT_MIN;
        int startingIndex = 0;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                
                if(solve(s, i, j)) {
                    if(j-i+1 > maxlen){
                        startingIndex = i;
                        maxlen = j-i+1;
                    }
                }
                
            }
        }

        return s.substr(startingIndex, maxlen);
    }
};