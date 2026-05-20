class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = 0; j <= i; j++) {
                mp[A[j]]++;
                mp[B[j]]--;
            }

            int count = 0;

            for (auto i : mp) {
                if (i.second == 0) {
                    count++;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};