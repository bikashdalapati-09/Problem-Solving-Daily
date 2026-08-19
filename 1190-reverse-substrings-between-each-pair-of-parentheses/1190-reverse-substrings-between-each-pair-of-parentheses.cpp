class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char, int>> st;
        int count = 0;
        string result = "";

        for(char ch : s){
            if(isalpha(ch)){
                count++;
            }
            if(ch == '('){
                st.push({ch, count});
            }
            else if(ch == ')'){
                int prev = st.top().second;
                reverse(result.begin() + prev, result.end());
                st.pop();
            }
            else{
                result += ch;
            }
        }
        return result;
    }
};