class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n-1;

        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans + 1;
    }
};