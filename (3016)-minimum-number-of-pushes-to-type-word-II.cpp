class Solution {
public:
    int minimumPushes(string word) {
        int result=0;
        vector<int>dummy(26,0);

        for(auto ch:word){
            dummy[ch-'a']++;
        }
        
        sort(dummy.begin(),dummy.end());      //after this dummy will be like : 0,0,0,...,3,5,6,7

        for(int i=25,j=0;i>=0;i--){
            if(dummy[i]==0) break;
            if(j<8){
                result+=(1*dummy[i]);
            }
            else if(j<16){
                result+=(2*dummy[i]);
            }
            else if(j<24){
                result+=(3*dummy[i]);
            }
            else{
                result+=(4*dummy[i]);
            }
            j++;
        }
        return result;
    }
};
