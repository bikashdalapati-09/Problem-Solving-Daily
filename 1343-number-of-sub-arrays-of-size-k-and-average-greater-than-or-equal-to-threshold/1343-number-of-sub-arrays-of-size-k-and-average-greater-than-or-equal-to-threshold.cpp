class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0;

        for(int i = 0;i <= n - k;i++){
            int avg = accumulate(arr.begin() +  i, arr.begin() + i + k, 0) / k;
            cout << avg << endl;
            if(avg >= threshold){
                count++;
            }
        }
        return count;
    }
};