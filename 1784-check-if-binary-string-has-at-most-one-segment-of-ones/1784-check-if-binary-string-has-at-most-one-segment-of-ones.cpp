class Solution {
public:
    bool checkOnesSegment(string s) {
        string copy = s;
        sort(copy.begin(), copy.end(), greater<int>());
        return s == copy;
    }
};