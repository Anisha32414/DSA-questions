class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n;
        int i;
        for(i=0;i<bits.size();){
            if((bits[i]==1 && bits[i+1]==0)||(bits[i]==1 && bits[i+1]==1)){
                n=i;
                i+=2;
            }
            else if(bits[i]==0){
                n=i;
                i+=1;
            }
        }
        return i-n==1;
    }
};
