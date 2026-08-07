class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum=0;
        int cost_sum=0;
        for(int g:gas) gas_sum+=g;
        for(int c:cost) cost_sum+=c;

        if(cost_sum>gas_sum) return -1;

        int res=0;
        int tank=0;
        for(int i=0;i<gas.size();i++){
            tank+=gas[i]-cost[i];

            if(tank<0){
                res=i+1;
                tank=0;
            }
        }
        return res;
    }
};
