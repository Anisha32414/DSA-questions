class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int left,right;
        left=0;
        right=arr.size()-1;
        while(left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        
    }
};
