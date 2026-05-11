class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int diff = arr[0] - arr[1];
        for (int i = 1; i < n - 1; i++) {
            int temp = arr[i] - arr[i + 1];
            if (temp != diff) {
                return false;
            }
        }
        return true;
    }
};