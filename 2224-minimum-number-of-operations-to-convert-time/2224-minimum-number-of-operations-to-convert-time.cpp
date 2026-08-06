class Solution {
public:
    int convertTime(string current, string correct) {
        int hr = stoi(correct.substr(0, 2)) - stoi(current.substr(0, 2));
        int min = stoi(correct.substr(3, 2)) - stoi(current.substr(3, 2));

        int total = hr * 60 + min;
        int count = 0;
        while (total >= 60) {
            count += 1;
            total -= 60;
        }
        while (total >= 15) {
            count += 1;
            total -= 15;
        }
        while (total >= 5) {
            count += 1;
            total -= 5;
        }
        while (total >= 1) {
            count += 1;
            total -= 1;
        }
        return count;
    }
};