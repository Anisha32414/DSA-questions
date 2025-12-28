class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return std::min(
            need1 * (long long)cost1 + need2 * (long long)cost2,

            std::min(
                need1 * (long long)costBoth
                + (need2 > need1 ? (need2 - need1) * (long long)cost2 : 0LL),

                need2 * (long long)costBoth
                + (need1 > need2 ? (need1 - need2) * (long long)cost1 : 0LL)
            )
        );
    }
};
