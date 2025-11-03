class Solution {
public:

    vector<int> pseEle(vector<int>&heights,int n){
        vector<int>res(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            res[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> nseEle(vector<int>&heights,int n){
        vector<int>res(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            res[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse=pseEle(heights,n);
        vector<int>nse=nseEle(heights,n);

        long long area=0;

        for(int i=0;i<n;i++){
            long long ar=heights[i]*(nse[i]-pse[i]-1);
            area=max(area,ar);
        }
        return (int)area;
    }
};
