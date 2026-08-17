class Solution { 
public: 
    vector<int> maxDepthAfterSplit(string seq) { 
        int n = seq.size(); 
        vector<int> ans(n); 
        stack<char> st; 
 
        for(int i = 0; i < n; i++){ 
            char ch = seq[i]; 
 
            if(ch == '('){ 
                st.push(ch); 
                ans[i] = st.size() % 2; 
            } 
            else{ 
                ans[i] = st.size() % 2; 
                st.pop(); 
            } 
        } 
 
        return ans; 
    } 
};