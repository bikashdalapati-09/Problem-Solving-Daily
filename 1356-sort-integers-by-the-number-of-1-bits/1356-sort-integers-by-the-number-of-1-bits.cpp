class Solution {
public:
    int solve(int n) {
        int count = 0;

        for(int i = 31;i >= 0;i--){
            if((n >> i) & 1){
                count++;
            } 
        }
        return count;
    }


    vector<int> sortByBits(vector<int>& arr) {


        auto comparetor = [&](int &a,int &b){
            int bitCount_a = solve(a);
            int bitCount_b = solve(b);

            if(bitCount_a == bitCount_b){
                return a < b;
            }
            return bitCount_a < bitCount_b;
        };
        

        sort(arr.begin(),arr.end(),comparetor);
        return arr;
    }
};