class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> mp;
        for (int i = 0; i < deck.size(); i++) {
            mp[deck[i]]++;
        }
        int res = 0;
        for (auto it : mp) {
            res = gcd(it.second, res);
        }
        return res > 1;
    }
};