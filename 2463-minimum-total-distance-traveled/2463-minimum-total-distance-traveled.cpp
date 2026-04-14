class Solution {
public:
    using ll = long long;
    ll solve(vector<int>& robot, vector<int>& positions, int i, int j, vector<vector<ll>> &dp){
        if(i >= robot.size()){
            return 0;
        }
        if(j >= positions.size()){
            return 1e12;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        ll take = abs(robot[i] - positions[j]) + solve(robot, positions, i+1, j+1, dp);
        ll skip = solve(robot, positions, i, j+1, dp);

        return dp[i][j] = min(take, skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> positions;

        for (int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos = factory[i][0];
            for (int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }

        vector<vector<ll>>dp (robot.size(), vector<ll>(positions.size(), -1));

        return solve(robot, positions, 0, 0, dp);
    }
};