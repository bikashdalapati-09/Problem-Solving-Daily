class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        string ans = "";

        int i = 0;
        int j = 0;
        bool flag = true;

        while (i < m && j < n) {
            if (flag) {
                ans += word1[i++];
                flag = !flag;
            } else {
                ans += word2[j++];
                flag = !flag;
            }
        }

        while (i < m) {
            ans += word1[i++];
        }

        while (j < n) {
            ans += word2[j++];
        }
        return ans;
    }
};