class Solution {
public:
    int countOperations(int num1, int num2) {
        int cntOperations=0;
        int a=max(num1,num2);
        int b=min(num1,num2);
        while(a && b){
            cntOperations+=a/b;
            a=a%b;
            swap(a,b);
        }
        return cntOperations;
    }
};
