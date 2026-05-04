class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int l = 0;
        int r = n - 1;

        int idx = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (letters[mid] <= target) {
                idx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << idx;
        if (idx >= n - 1) {
            return letters[0];
        }
        return letters[idx + 1];
    }
};