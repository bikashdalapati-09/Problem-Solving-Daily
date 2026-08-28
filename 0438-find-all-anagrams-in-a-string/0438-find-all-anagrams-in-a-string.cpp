class Solution {
public:
    bool isSame(string a, string b) {
        vector<int> freq(26, 0);

        for (char c : a) {
            freq[c - 'a']++;
        }

        for (char c : b) {
            freq[c - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return false;
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        vector<int> ans;

        int i = 0;
        int j = 0;

        while (j < n) {

            if (j - i + 1 > p.size()) {
                i++;
            }
            if (j - i + 1 == p.size()) {
                string str = s.substr(i, j - i + 1);
                if (isSame(str, p)) {
                    ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};