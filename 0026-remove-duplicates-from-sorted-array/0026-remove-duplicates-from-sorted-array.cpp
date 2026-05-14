class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = -1;

        while(i < n){
            if(j == -1 || nums[j] != nums[i]){
                nums[++j] = nums[i];
            }
            i++;
        }
        return j + 1;
    }
};