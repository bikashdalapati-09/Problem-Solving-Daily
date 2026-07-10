class Solution {
public:
    string padding(int num) {
        string s = to_string(num);
        int pad = 4 - s.size();
        string ans = "";

        while (pad--) {
            ans += '0';
        }
        cout << ans + s << endl;
        return ans + s;
    }
    int generateKey(int num1, int num2, int num3) {
        string a = padding(num1);
        string b = padding(num2);
        string c = padding(num3);

        string result = "";

        for (int i = 0; i < 4; i++) {
            result += min({a[i], b[i], c[i]});
        }

        return stoi(result);
    }
};