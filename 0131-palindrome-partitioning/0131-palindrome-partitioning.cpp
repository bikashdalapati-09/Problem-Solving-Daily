class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(string s, int idx, vector<string>& curr, vector<vector<string>>& result){
        if(idx >= s.size()){
            result.push_back(curr);
            return;
        }

        for(int i = idx;i < s.size();i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string> curr;
        vector<vector<string>> result;

        solve(s, 0, curr, result);

        return result;
    }
};