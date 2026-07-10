class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string trimTrailingVowels(string s) {
        int n = s.size();
        int count = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (isVowel(s[i])) {
                count++;
            } else {
                break;
            }
        }
        return s.substr(0, n - count);
    }
};