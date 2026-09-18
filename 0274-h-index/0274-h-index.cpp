class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        sort(citations.begin(), citations.end());

        int low = 0;
        int high = n;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int index = n - mid;

            if(mid == 0 || citations[index] >= mid) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};