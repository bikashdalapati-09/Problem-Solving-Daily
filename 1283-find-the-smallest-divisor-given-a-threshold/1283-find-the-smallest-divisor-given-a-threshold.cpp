class Solution {
public:
    int check(vector<int>& nums, int mid){
        long long sum = 0;
        for(auto i: nums){
            sum += (ceil((double)i / mid));
        }
        cout << mid << "->" << sum << endl;
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;
            
            if(check(nums, mid) <= threshold){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};