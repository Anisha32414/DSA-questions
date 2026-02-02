class Solution {
public:
    void all_permutation(vector<vector<int>>&answer,vector<int>&term,vector<int>helper,vector<int>nums){
        if(nums.size()==term.size()){       // base condition
            answer.push_back(term);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(helper[i]!=1){
                helper[i]=1;
                term.push_back(nums[i]);
                all_permutation(answer,term,helper,nums);
                helper[i]=0;
                term.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>term;
        vector<int>helper(nums.size(),0);
        all_permutation(answer,term,helper,nums);
        return answer;
    }
};
