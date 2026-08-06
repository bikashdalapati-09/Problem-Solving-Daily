class Solution {
public:
    bool hasMatch(string s, string p) {
        int idx = p.find("*");
        string a = p.substr(0, idx);
        string b = p.substr(idx + 1);
        int i = s.find(a);
        int j = s.rfind(b);
        return i != -1 && j != -1 && i + a.size() <= j;
    }
};