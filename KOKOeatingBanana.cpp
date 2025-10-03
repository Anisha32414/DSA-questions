class Solution {
public:

    int findMax(vector<int> piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int>piles, int hourly) {
        long long totalH = 0;
        for(int i = 0; i < piles.size(); i++) {
            totalH += ceil((double)piles[i] / (double)hourly);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
       int low = 1, high = findMax(piles);

       while(low <= high) {
        int mid = low + (high - low) / 2;
        long long totalHours = calculateTotalHours(piles, mid);
        if(totalHours <= h) {
            high = mid - 1;
        } else{ 
            low = mid + 1;
        }
       }
    return low;
    }
};
