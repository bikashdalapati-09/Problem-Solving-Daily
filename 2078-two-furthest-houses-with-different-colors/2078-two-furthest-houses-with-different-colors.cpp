class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int furthest = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (colors[i] != colors[j]){
                    furthest = max(furthest, j - i);
                }
            }
        }
        return furthest;
    }
};