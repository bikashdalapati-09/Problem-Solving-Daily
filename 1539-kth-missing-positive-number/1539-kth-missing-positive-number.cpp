class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st(arr.begin(),arr.end());
        int ans = 0;
        int i = 1;

        while (true) {
            if (st.find(i) == st.end()) {
                k--;
                ans = i;
                if (k == 0) {
                    return ans;
                }
            }
            i++;
        }
        return 0;
    }
};