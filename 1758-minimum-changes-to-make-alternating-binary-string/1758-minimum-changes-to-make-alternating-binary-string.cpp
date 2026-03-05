class Solution {
public:
    int checkDiff(string &a, string &b){
        int count = 0;
        for(int i = 0;i < a.size();i++){
            if(a[i] != b[i]) count++;
        }
        return count;
    }
    int minOperations(string s) {
        int n = s.size();

        string stZero = "";
        string stOne = "";

        for(int i = 0;i < n;i++){
            if(i % 2 == 0){
                stZero += '0';
                stOne += '1';
            }
            else{
                stZero += '1';
                stOne += '0';
            }
        }

        int result = min(checkDiff(s, stZero), checkDiff(s, stOne));

        return result;
    }
};