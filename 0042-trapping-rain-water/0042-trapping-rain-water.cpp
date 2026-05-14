class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftHigh(n);
        vector<int> rightHigh(n);

        leftHigh[0] = height[0];
        rightHigh[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++) {
            leftHigh[i] = max(leftHigh[i - 1], height[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            rightHigh[i] = max(rightHigh[i + 1], height[i]);
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += min(leftHigh[i], rightHigh[i]) - height[i];
        }

        return result;
    }
};