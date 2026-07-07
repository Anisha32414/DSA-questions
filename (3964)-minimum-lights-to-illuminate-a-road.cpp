class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);
                diff[l]++;
                if (r + 1 < n) diff[r + 1]--;
            }
        }
        vector<int> covered(n, 0);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            covered[i] = (cur > 0);
        }
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (covered[i]) {
                i++;
                continue;
            }
            int end = i;
            while (end + 1 < n && !covered[end + 1]) end++;
            int pos = i;
            while (pos <= end) {
                int bulb = min(pos + 1, n - 1);
                ans++;
                pos = min(n - 1, bulb + 1) + 1;
            }
            i = end + 1;
        }
        return ans;
    
};
