class Solution {
public:

    vector<int> pseEle(vector<int>&arr,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nseEle(vector<int>&arr,int n){
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    
    int getHistogram(vector<int>&arr,int n){
        vector<int>pse=pseEle(arr,n);
        vector<int>nse=nseEle(arr,n);

        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(1LL*arr[i]*(nse[i]-pse[i]-1)));
        }
        return (int)ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m=matrix.size();   //rows
        int n=matrix[0].size();   //col

        vector<vector<int>>preSum(m,vector<int>(n));
           
        for(int j=0;j<n;j++){
            int sum=0;
            for(int i=0;i<m;i++){
                if(matrix[i][j]=='0') sum=0;
                else sum+=1;
                preSum[i][j]=sum;
            }
        }

        int maxArea=0;

        for(int i=0;i<m;i++){
            maxArea=max(maxArea,getHistogram(preSum[i],n));
        }
        return maxArea;
    }
};
