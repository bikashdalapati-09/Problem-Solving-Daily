class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();

        sort(items.begin(), items.end());

        int maxBeauty = 0;

        for(int i = 0; i < n; i++){
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        vector<int> ans;

        for(int query : queries){
            int l = 0;
            int r = n - 1;
            int beauty = 0;

            while(l <= r){
                int mid = l + (r - l) / 2;

                if(items[mid][0] <= query){
                    beauty = items[mid][1];
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }

            ans.push_back(beauty);
        }

        return ans;
    }
};