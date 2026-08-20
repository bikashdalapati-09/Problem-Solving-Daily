class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;
        vector<int> ans;

        for (auto i : asteroids) {

            if (st.empty()) {
                st.push(i);
            }

            else if (i < 0 && st.top() > 0) {

                bool destroyed = false;

                while (!st.empty() && st.top() > 0) {

                    if (st.top() < abs(i)) {
                        st.pop();
                    } else if (st.top() == abs(i)) {
                        st.pop();
                        destroyed = true;
                        break;
                    } else {
                        destroyed = true;
                        break;
                    }
                }

                if (!destroyed) {
                    st.push(i);
                }
            }

            else {
                st.push(i);
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};