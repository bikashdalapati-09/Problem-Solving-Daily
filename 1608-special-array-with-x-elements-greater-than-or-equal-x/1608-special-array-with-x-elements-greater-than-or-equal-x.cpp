class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        int l = 0;
        int r = n ;

        while(l <= r){
            int mid = l + (r - l) / 2;

            int i = lower_bound(begin(nums), end(nums), mid) - begin(nums);

            if(n-i == mid){
                return mid;
            }
            else if(n-i > mid){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return -1;
    }
};