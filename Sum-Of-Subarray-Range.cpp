class Solution {
public:
    vector<int> pgeEle(vector<int>&nums,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> ngeEle(vector<int>&nums,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pseEle(vector<int>&nums,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;

    }

    vector<int> nseEle(vector<int>&nums,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumMax(vector<int>&nums,int n){
        long long res=0;

        vector<int>pge=pgeEle(nums,n);
        vector<int>nge=ngeEle(nums,n);

        for(int i=0;i<n;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            res=res+(1LL*right*left*nums[i]);
        }
        return res;
    }

    long long sumMin(vector<int>&nums,int n){
        long long res=0;

        vector<int>pse=pseEle(nums,n);
        vector<int>nse=nseEle(nums,n);

        for(int i=0;i<n;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            res=res+(1LL*right*left*nums[i]);
        }
        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        return sumMax(nums,n)-sumMin(nums,n);
    }
};
