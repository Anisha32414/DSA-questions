class Solution {
    public:
    void rotateArr(vector <int>&arr,int d){
        int n=arr.size();
        d=d%n;
        if(d==0 ||n==0 || n==d)
        return;
        
        reverse(arr.begin(),arr.begin()+d);
        reverse(arr.begin()+d,arr.end());
        reverse(arr.begin(),arr.end());
        
    }
};
