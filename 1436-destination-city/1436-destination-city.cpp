class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> vals;
        for(auto& path : paths) {
            vals[path[0]] += 2;
            vals[path[1]] += 1;
        }
        for(auto [key, val] : vals){
            if(val == 1) {
                return key;
            }
        }
        return "";
    }
};