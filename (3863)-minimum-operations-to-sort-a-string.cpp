class Solution {
public:
    int minOperations(string s) {
        if(s.size()==1) return 0;

        if(s.size()==2){
            if(s[0]>s[1]) return -1;
            return 0;
        }

        string dummy=s;
        sort(dummy.begin(),dummy.end());

        if(dummy==s) return 0;

        if(dummy[0]==s[0] || dummy[s.size()-1]==s[s.size()-1]) return 1;
        
        string a=s;
        string b=s;

        sort(a.begin(),a.end()-1);
        sort(a.begin()+1,a.end());

        sort(b.begin()+1,b.end());
        sort(b.begin(),b.end()-1);
        

        if(a==dummy || b==dummy) return 2;

        return 3;
    }
};
