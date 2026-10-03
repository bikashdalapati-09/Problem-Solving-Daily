class Solution {
public:
    bool isPossible(vector<int> nums, int val, int k) {
        long long timeTaken = 0;
        for (int i = 0; i < nums.size(); i++) {
            timeTaken += (ceil((double)nums[i] / val));
        }
        return timeTaken <= k;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};