class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> st;
        for(auto i: nums){
            st.insert(i);
        }

        int i = 1;
        while(true){
            if(st.find(i * k) == st.end()){
                return i * k;
            }
            i++;
        }
        return 0;
    }
};