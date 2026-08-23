class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for(auto i : nums1){
            mp1[i]++;
        }
        for(auto i : nums2){
            mp2[i]++;
        }

        int ans1 = 0;
        int ans2 = 0;

        for(auto [key, val]: mp1){
            if(mp2.count(key)){
                ans1 += val;
            }
        }
        for(auto [key, val]: mp2){
            if(mp1.count(key)){
                ans2 += val;
            }
        }
        return {ans1, ans2};
    }
};