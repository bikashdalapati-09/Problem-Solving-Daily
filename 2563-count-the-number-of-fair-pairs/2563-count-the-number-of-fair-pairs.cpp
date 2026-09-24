class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        long long count = 0;

        for(int i = 0;i < n - 1;i++){
            int curr = nums[i];

            int low = lower - curr;
            int high = upper - curr ;

            int lowIdx = lower_bound(nums.begin() + i + 1, nums.end(), low) - nums.begin();
            int x = lowIdx - i - 1;
            int upIdx = upper_bound(nums.begin() + i + 1, nums.end(), high) - nums.begin();
            int y = upIdx - i - 1;

            cout << x << " " << y << endl;  // 0 1 4 4 5 7
            count += (y - x);
        }
        return count;
    }
};