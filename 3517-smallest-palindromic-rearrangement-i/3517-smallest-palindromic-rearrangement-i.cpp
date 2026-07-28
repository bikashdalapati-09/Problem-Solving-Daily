class Solution {
public:
    string smallestPalindrome(string s) {
        unordered_map<char,int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        int oddCount = 0;
        char midChar = '\0';

        for(auto i : mp){
            if(i.second % 2 != 0){
                midChar = i.first;
                oddCount++;
            }
        }

        if(oddCount > 1){
            return "";
        }

        vector<char> chars;
        for(auto [ch, count] : mp){
            for(int i = 0;i < count/2;i++){
                chars.push_back(ch);
            }
        }

        sort(chars.begin(),chars.end());
        string firstHalf(chars.begin(),chars.end());
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(),secondHalf.end());

        string ans = "";
        if(oddCount == 1){
            ans = firstHalf + midChar + secondHalf;
        }
        else{
            ans = firstHalf + secondHalf;
        }
        return ans;
    }
};