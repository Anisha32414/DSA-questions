class Solution {
public:
    string defangIPaddr(string address) {
        string s;
        for(int i=0;i<address.size();i++){
            char k=address[i];
            if(k=='.'){
                char l='[';
                char m=']';
                s.push_back(l);
                s.push_back(k);
                s.push_back(m);
            } 
            else {
                s.push_back(k);
            }
        } 
        return s;  
    }
};
