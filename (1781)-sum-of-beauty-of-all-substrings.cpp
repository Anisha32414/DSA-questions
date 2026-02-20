class Solution {
public:
    int beautySum(string s) {
        int res=0;
        for(int l=0;l<s.size();l++){
            vector<int>freq(26,0);

            for(int r=l;r<s.size();r++){

                freq[s[r]-'a']++;

                int maxe=0;
                int mine=s.size();
                for(int i=0;i<26;i++){
                    if(freq[i]!=0){
                        maxe=max(maxe,freq[i]);
                        mine=min(mine,freq[i]);
                    }
                }
                res+=(maxe-mine);
            }
        }
        return res;
    }
}; 
