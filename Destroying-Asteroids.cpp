class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long current_mass = mass;

        for (int ast : asteroids) {
            if (current_mass >= ast) {
                current_mass += ast;
            } else {
                return false;
            }
        }
        return true;
    }
};
