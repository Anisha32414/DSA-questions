class Solution {
public:
    void resultant_array(int k, int n , vector<vector<int>>&res,vector<int>&term,int &sum,int curr,int num){
        if(sum==n && curr==k){
            res.push_back(term);
            return;
        }
        
        if(sum>n || num>9 || curr>k) return;

        if(curr<k){
            term.push_back(num);
            sum+=num;
            resultant_array(k,n,res,term,sum,curr+1,num+1);
            sum-=num;

            term.pop_back();
            resultant_array(k,n,res,term,sum,curr,num+1);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>term;
        int sum=0;
        resultant_array(k,n,res,term,sum,0,1);
        return res;
    }
};
