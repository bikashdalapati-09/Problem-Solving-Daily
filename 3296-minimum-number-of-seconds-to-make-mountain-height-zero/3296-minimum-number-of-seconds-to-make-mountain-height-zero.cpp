class Solution {
public:
    using ll = long long;
    bool check(ll mid, int mountainHeight, vector<int>& workerTimes) {
        ll h = 0;

        for (auto& t : workerTimes) {
            h += (ll)(sqrt(2.0 * mid / t + 0.25) - 0.5);

            if (h >= mountainHeight) {
                return true;
            }
        }
        return h >= mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        ll left = 1;
        ll right = (ll)maxTime * mountainHeight * (mountainHeight + 1) / 2;

        ll result = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;

            if (check(mid, mountainHeight, workerTimes)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};