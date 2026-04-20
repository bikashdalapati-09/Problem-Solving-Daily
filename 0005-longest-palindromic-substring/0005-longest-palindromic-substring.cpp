class Solution {
public:
    bool isPailndrome(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        string res = "";
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                string temp = s.substr(i, j);
                if (isPailndrome(temp)) {
                    if (len < temp.size()) {
                        len = temp.size();
                        res = temp;
                    }
                }
            }
        }
        return res;
    }
};