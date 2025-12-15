class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==0 && high%2==0)   //even both
            return (high-low)/2;
        else if(low%2!=0 && high%2!=0)   //both odd
            return (high-low)/2+1;
        else if(low%2==0 && high%2!=0)   // low even
            return (high-low)/2+1;
        else   //high even
            return (high-low)/2+1;
    }
};
