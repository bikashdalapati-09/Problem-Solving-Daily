class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = INT_MAX;
        int odd = 0;
        int even = 0;

        for (auto x : nums1) {
            if (x % 2 != 0) {
                odd++;
                mini = min(mini, x);
            }
            else{
                even++;
            }
        }

        if (odd == n || even == n) {
            return true;
        }


        for (auto x : nums1) {
            if (x % 2 == 0 && x <= mini) {
                return false;
            }
        }

        return true;
    }
};