class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int n1=s1.size()-1;
        int n2=s2.size()-1;
        string res="";
        int carry=0;
        
        while(n1>=0 || n2>=0 || carry){
            int sum=carry;
            if(n1>=0)sum+=s1[n1--]-'0';
            if(n2>=0)sum+=s2[n2--]-'0';
            
            res+=(sum%2)+'0';
            carry=sum/2;
            
        }
        reverse(res.begin(),res.end());
        int k=res.find_first_not_of('0');
        if(k==string::npos)return "0";
        return res.substr(k);
    }
};
