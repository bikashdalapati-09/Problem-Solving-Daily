class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        
        int n = potions.size();
        vector<int> ans(spells.size());

        sort(potions.begin(), potions.end());

        for (int i = 0; i < spells.size(); i++) {
            int spell = spells[i];

            long long mod = (success + spell - 1) / spell;

            int idx = lower_bound(potions.begin(), potions.end(), mod)
                      - potions.begin();

            ans[i] = n - idx;
        }

        return ans;
    }
};