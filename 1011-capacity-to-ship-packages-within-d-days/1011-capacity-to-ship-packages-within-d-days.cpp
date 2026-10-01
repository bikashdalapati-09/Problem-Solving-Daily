class Solution {
public:
    int isPossible(vector<int>& weights, int mid){
        int days = 1;
        int count = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (count + weights[i] <= mid) {
                count += weights[i];
            } else {
                days++;
                count = weights[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(isPossible(weights, mid) <= days){
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