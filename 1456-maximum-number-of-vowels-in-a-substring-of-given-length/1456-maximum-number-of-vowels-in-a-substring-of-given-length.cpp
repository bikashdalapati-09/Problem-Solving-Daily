class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();

        int i = 0;
        int j = 0;

        string str = "";
        int count = 0;

        int ans = 0;

        while (j < n) {
            if (isVowel(s[j])) {
                count++;
            }

            while (j - i + 1 > k) {
                if (isVowel(s[i])) {
                    count--;
                }
                i++;
            }

            ans = max(ans, count);

            j++;
        }

        return ans;
    }
};