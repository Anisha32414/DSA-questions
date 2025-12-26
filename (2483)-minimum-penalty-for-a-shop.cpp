class Solution {
public:
    int bestClosingTime(string customers) {
        int pen=0;
        for(char c:customers){
            if(c=='Y') pen++;
        }

        int best=pen;
        int ans=0;
        
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') pen--;
            else pen++;

            if(pen<best){
                best=pen;
                ans=i+1;
            }
        }
        return ans;
    }
};
