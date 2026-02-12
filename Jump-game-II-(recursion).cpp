class Solution {
public:
    int jump_game(vector<int>&nums,int index,int jump){
        if(index>=nums.size()-1){
            return jump;
        }
        int mini=INT_MAX;
        for(int i=1;i<=nums[index];i++){
            mini=min(mini,jump_game(nums,index+i,jump+1));
        }
        return mini;
    }
    
    int jump(vector<int>& nums) {
       
        return jump_game(nums,0,0);
       
    }
};
