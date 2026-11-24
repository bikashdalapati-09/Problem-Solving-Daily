class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int i = 0;
        int j = n-1;

        while(i < j){
            int left = height[i];
            int right = height[j];
            int height = min(left, right);
            int width = j - i;

            ans = max(ans, (height * width));
            
            (left < right) ? i++ : j--;
        }
        return ans;
    }
};