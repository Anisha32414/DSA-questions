class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int res = INT_MAX;

        for (auto &it : mp) {
            vector<int> &v = it.second;

            if (v.size() < 3) continue;

            for (int i = 0; i + 2 < v.size(); i++) {
                int dist = v[i + 2] - v[i];
                res = min(res, 2*dist);
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};
