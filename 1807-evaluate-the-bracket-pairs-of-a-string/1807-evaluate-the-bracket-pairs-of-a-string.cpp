class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> st;

        for(auto duo : knowledge){
            st[duo[0]] = duo[1];
        }

        bool flag = false;
        string temp = "";
        string ans = "";

        for(char ch : s){
            

            if(ch == '('){
                flag = true;
                continue;
            }
            if(ch == ')'){
                flag = false;        
                temp = st.count(temp) ? st[temp] : "?";
                ans += temp;
                temp = "";
                continue;
            }

            if(flag){
                temp += ch;
            }

            if(!flag && ch != '(' && ch != ')'){
                ans += ch;
            }

        }
        return ans;
    }
};