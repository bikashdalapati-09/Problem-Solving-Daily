class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int i = 0;
        int j = 0;

        string str = "";
        string ans = s;
        int count = 0;

        while (j < n) {
            str += s[j];

            if (s[j] == '1') {
                count++;
            }

            if (count == k) {
                string curr = s.substr(i, j - i + 1);

                if (ans.size() > curr.size()) {
                    ans = curr;
                } else if (ans.size() == curr.size()) {
                    ans = min(ans, curr);
                }
            }

            while (count >= k) {
                if (s[i] == '1') {
                    count--;
                }

                i++;

                if (count == k) {
                    string curr = s.substr(i, j - i + 1);

                    if (ans.size() > curr.size()) {
                        ans = curr;
                    } else if (ans.size() == curr.size()) {
                        ans = min(ans, curr);
                    }
                }
            }

            j++;
        }

        int ones = std::count(ans.begin(), ans.end(), '1');


        return ones == k ? ans : "";
    }
};