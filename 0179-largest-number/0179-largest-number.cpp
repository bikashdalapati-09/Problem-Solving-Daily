class Solution {
public:
    static bool customCompare(string a, string b) {
        return (a + b) > (b + a);
    }

    string largestNumber(vector<int>& nums) {
        vector<string> str;
        string ans = "";
        string prev = "";
        bool allZero = true;

        for (auto i : nums) {
            if(i != 0) allZero = false;
            str.push_back(to_string(i));
        }

        sort(str.begin(), str.end(), customCompare);

        for(auto ch : str){
            ans += ch;
            prev = ch;
        }

        return allZero ? "0" : ans;
    }
};