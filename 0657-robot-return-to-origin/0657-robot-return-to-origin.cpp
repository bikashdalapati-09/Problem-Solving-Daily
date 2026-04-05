class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> arr(2, 0);

        for (auto i : moves) {
            if (i == 'L') {
                arr[1]++;
            } else if (i == 'R') {
                arr[1]--;
            } else if (i == 'U') {
                arr[0]++;
            } else {
                arr[0]--;
            }
        }
        return arr[0] == 0 && arr[1] == 0;
    }
};