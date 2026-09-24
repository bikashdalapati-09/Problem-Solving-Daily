class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = potions.size();
        vector<int> result;
        sort(potions.begin(), potions.end());

        for (auto spell : spells) {
            int l = 0;
            int r = n - 1;
            int ans = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                long long mul = 1LL * spell * potions[mid];
                if (mul < success) {
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            result.push_back(n - ans - 1);
        }
        return result;
    }
};