class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation=0;
        vector<int>st;
        st.push_back(0);
        for(int n:nums){
            while(!st.empty() && st.back()>n){
                st.pop_back();
                operation++;
            }
            if(st.back()==n) continue;

            if(n>0) st.push_back(n);
        }
        while(!st.empty() && st.back()>0){
            st.pop_back();
            operation++;
        }
        return operation;
    }
};
