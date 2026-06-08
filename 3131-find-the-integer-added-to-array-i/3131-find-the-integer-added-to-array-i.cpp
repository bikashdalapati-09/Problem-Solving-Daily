class Solution {
public:
    int addedInteger(vector<int>& v1, vector<int>& v2) {
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int n = v1.size();
        return v2[n - 1] - v1[n - 1];
    }
};