class Solution {
public:
    bool check(vector<int>& candies, int mid, long long k){
        long long count = 0;

        for(auto i : candies){
            count += i / mid;

            if(count >= k){
                return true;
            }
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1;
        int r = *max_element(candies.begin(), candies.end());
        int ans = 0;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(candies, mid, k)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return ans;
    }
};