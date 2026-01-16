class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        int original_no = x;
        long rev_no = 0;

        while (x != 0) {
            int digit = x % 10;

            rev_no = rev_no * 10 + digit;
            x = x / 10;
        }

        if (original_no == rev_no) {
            return true;
        } else
            return false;
    }
};