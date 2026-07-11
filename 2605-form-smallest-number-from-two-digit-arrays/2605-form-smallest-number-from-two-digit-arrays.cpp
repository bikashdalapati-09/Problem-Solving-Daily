class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        for(auto i : nums2){
            if(st.find(i) != st.end()){
                return i;
            }
        }
        return nums1[0] < nums2[0] ? nums1[0] * 10 + nums2[0] : nums2[0] * 10 + nums1[0];
    }
};