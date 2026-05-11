class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n =  arr.size();

        for(int i = 0;i < n;i++){
            for(int j = i; j < n;j++){
                if((j-i+1) % 2 == 1){
                    int temp = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
                    sum += temp;
                }
            }
        }
        return sum;
    }
};