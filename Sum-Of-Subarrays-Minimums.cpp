class Solution {
public:

    vector<int> nextSmallerElement(vector<int>&arr,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            res[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return res;
    }
    vector<int> previousSmallerElement(vector<int>&arr,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            res[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();

        vector<int>nse=nextSmallerElement(arr,n);
        vector<int>pse=previousSmallerElement(arr,n);

        int answer=0;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            answer=(answer+(right*left*1LL*arr[i])%mod)%mod;
        }
        return answer;
    }
};
