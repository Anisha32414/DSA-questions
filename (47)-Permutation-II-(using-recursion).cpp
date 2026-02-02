class Solution {
public:
    void permutations(vector<int>num,vector<vector<int>>&res,vector<int>&term,vector<int>helper) {
       if(term.size()==num.size()){
          res.push_back(term);
          return;
       }
       
       for(int i=0;i<num.size();i++){

           if(i>0 && num[i-1]==num[i] && helper[i-1]==0) continue;

           if(helper[i]!=1){
              helper[i]=1;
              term.push_back(num[i]);
              permutations(num,res,term,helper);
              helper[i]=0;
              term.pop_back();  
          }
       }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>>res;
        vector<int>term;
        vector<int>helper(num.size(),0);
        permutations(num,res,term,helper);
        return res;
    }
};
