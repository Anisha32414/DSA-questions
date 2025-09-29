class Solution {
public:

int lowerBound(vector<int>arr,int n,int x){
    int left=0;
    int right=arr.size()-1;
    int ans=n;
    
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]>=x){
            right=mid-1;
            ans=mid;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>arr,int n,int x){
    int left=0;
    int right=arr.size()-1;
    int ans=n;
    
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]>x){
            right=mid-1;
            ans=mid;
        }
        else{
            left=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& arr, int x) {
        vector<int>res;
        int n=arr.size();
        int lb=lowerBound(arr,n,x);
        if(lb==n || arr[lb]!=x) {
            return {-1,-1};
        }
        return {lb,upperBound(arr,n,x)-1};
    }
};
