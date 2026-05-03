class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = hours[i] + hours[j];
                if (temp % 24 == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};