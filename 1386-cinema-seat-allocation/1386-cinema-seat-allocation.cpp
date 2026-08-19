class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;

        for(auto eachRow : reservedSeats){
            int row = eachRow[0];
            int col = eachRow[1];

            if(col != 1 && col != 10){
                mp[row].push_back(col);
            }
        }

        int count = 0;

        int rem = n - mp.size();

        count += rem * 2;

        for(auto& i : mp){

            vector<int> arr = i.second;

            bool left = true;  
            bool middle = true;
            bool right = true; 

            for(int seat : arr){

                if(seat >= 2 && seat <= 5){
                    left = false;
                }

                if(seat >= 4 && seat <= 7){
                    middle = false;
                }

                if(seat >= 6 && seat <= 9){
                    right = false;
                }
            }

            if(left && right){
                count += 2;
            }
            else if(left || middle || right){
                count += 1;
            }
        }

        return count;
    }
};