class Solution {
public:
    string reverseByType(string s) {
        string ch = "";
        string sym = "";

        for (auto i : s) {
            if (isalpha(i)) {
                ch += i;
            } else {
                sym += i;
            }
        }
        reverse(ch.begin(), ch.end());
        reverse(sym.begin(), sym.end());

        int i = 0;
        int j = 0;

        for (int k = 0; k < s.size(); k++) {
            if (isalpha(s[k])) {
                s[k] = ch[i++];
            } else {
                s[k] = sym[j++];
            }
        }

        return s;
    }
};