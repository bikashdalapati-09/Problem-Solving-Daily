class Solution {
public:
    bool isSame(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if (m > n)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int i = 0;
        int j = 0;

        while (j < n) {

            freq2[s2[j] - 'a']++;

            if (j - i + 1 > m) {
                freq2[s2[i] - 'a']--;
                i++;
            }

            if (j - i + 1 == m) {
                if (isSame(freq1, freq2)) {
                    return true;
                }
            }

            j++;
        }

        return false;
    }
};