class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0;

        int i = 0, j = 0;
        int sum = 0;

        while (j < n) {
            sum += arr[j];

            while (j - i + 1 > k) {
                sum -= arr[i];
                i++;
            }

            if (j - i + 1 == k) {
                int avg = sum / k;

                if (avg >= threshold) {
                    count++;
                }
            }

            j++;
        }

        return count;
    }
};