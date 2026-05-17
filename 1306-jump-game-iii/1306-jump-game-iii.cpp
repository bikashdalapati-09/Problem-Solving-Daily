class Solution {
public:
    bool solve(vector<int>& arr, int i) {
        if (i < 0 || i >= arr.size() || arr[i] < 0) {
            return false;
        }
        if (arr[i] == 0) {
            return true;
        }

        arr[i] = -arr[i];
        bool a = solve(arr, i + arr[i]);
        bool b = solve(arr, i - arr[i]);

        return a || b;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        return solve(arr, start);
    }
};