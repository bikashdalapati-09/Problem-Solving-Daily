class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int m = items.size();
        int n = queries.size();

        sort(items.begin(), items.end());

        int maxBeauty = 0;

        for (int i = 0; i < m; i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {

            int query = queries[i];

            int l = 0;
            int r = m - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (items[mid][0] <= query) {
                    ans[i] = max(ans[i], items[mid][1]);
                    l = mid + 1;
                }

                else {
                    r = mid - 1;
                }
            }
        }
        return ans;
    }
};