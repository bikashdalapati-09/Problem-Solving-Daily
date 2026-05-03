class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string dblgoal = goal + goal;
        return dblgoal.find(s) != string :: npos;
    }
};