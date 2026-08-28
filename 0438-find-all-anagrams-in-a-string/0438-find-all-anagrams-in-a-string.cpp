class Solution {
public:
    bool isSame(string a, string b){
        unordered_map<char, int>mp;

        for(char i: a){
            mp[i]++;
        }

        for(char i: b){
            mp[i]--;
            if(mp[i] == 0){
                mp.erase(i);
            }
        }
        return mp.size() == 0;

    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        vector<int> ans;

        int i = 0;
        int j = 0;

        while(j < n){
    
            if(j - i + 1 > p.size()){
                i++;
            }
            if(j - i + 1 == p.size()){
                string str = s.substr(i, j-i+1);
                if(isSame(str, p)){
                    ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};