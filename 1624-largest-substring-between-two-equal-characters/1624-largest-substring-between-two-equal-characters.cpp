class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> mp;
        int maxi = 0;

        for(int i = 0;i < s.size();i++){
            mp[s[i]].push_back(i);
        }

        for(auto [ch, arr] : mp){
            int diff = abs(arr[0] - arr[arr.size() - 1]);
            maxi = max(maxi, diff);
        }
        return maxi - 1;
    }
};