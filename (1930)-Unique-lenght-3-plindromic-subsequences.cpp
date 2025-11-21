class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int count=0;
        int n=s.size();

        vector<int>first(26,-1),last(26,-1);

        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(first[c]==-1) first[c]=i;
            last[c]=i;
        }
        
        for(int i=0;i<26;i++){
            if(first[i]==-1) continue;
            int l=first[i];
            int r=last[i];

            if(l>=r) continue;
            
            vector<bool>seen(26,false);

            for(int j=l+1;j<r;j++){
                seen[s[j]-'a']=true;
            }

            for(int k=0;k<26;k++){
                if(seen[k]==true) count++;
            }

        }
        return count;
    }
};
