class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
       
        vector<bool> aux(n+1,true);
        aux[0]=false,aux[1]=false;
        for(int i=2;i*i<n;i++){
            if(aux[i]){
                for(int j=i*i;j<n;j+=i){
                    aux[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(aux[i])
               count++;
        }
        return count;
    }
};
