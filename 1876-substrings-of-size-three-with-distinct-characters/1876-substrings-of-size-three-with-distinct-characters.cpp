class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0;i <= n-3;i++){
            string str = s.substr(i, 3);
            cout << str << endl;

            vector<int> arr(26, 0);
            for(auto i: str){
                arr[i - 'a']++;
            }
            bool flag = true;
            for(auto i : arr){
                if(i > 1){
                    flag = false;
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};