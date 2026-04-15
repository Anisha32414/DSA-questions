class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        for(int i=0;i<n;i++){
            int right=(startIndex+i)%n;
            int left=(startIndex-i+n)%n;

            if(words[left]==target || words[right]==target) return i;
        }
        return -1;
    }
};
