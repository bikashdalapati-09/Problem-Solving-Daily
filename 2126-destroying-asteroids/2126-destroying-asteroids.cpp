class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        if (n == 1) {
            return mass >= asteroids[0];
        }

        sort(asteroids.begin(), asteroids.end());
        if(mass < asteroids[0]) {
            return false;
        }

        long long sum = mass;

        for (int i = 0; i < n - 1; i++) {
            sum += asteroids[i];
            if (sum < asteroids[i + 1]) {
                return false;
            }
        }
        return true;
    }
};