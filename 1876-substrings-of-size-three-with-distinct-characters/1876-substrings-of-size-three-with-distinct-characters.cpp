class Solution {
public:
    bool isSame(string s) {
        vector<int> arr(26, 0);

        for (auto i : s) {
            arr[i - 'a']++;
        }

        for (auto i : arr) {
            if (i > 1) {
                return false;
            }
        }
        return true;
    }
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;

        int i = 0;
        int j = 0;

        while (j < n) {

            if (j - i + 1 > 3) {
                i++;
            }
            if (j - i + 1 == 3) {
                string str = s.substr(i, 3);
                cout << str << endl;
                if (isSame(str)) {
                    count++;
                }
            }
            j++;
        }
        return count;
    }
};