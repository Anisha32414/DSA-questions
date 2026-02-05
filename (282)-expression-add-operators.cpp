class Solution {
public:
    void expression(string num,int target,vector<string>&res,string curr,long long sum,long long prev,int index){
        if(index==num.size()){
            if(sum==target){
                res.push_back(curr);
            }
            return;
        }
        long long currNum=0;
        string currStr="";

        for(int i=index;i<num.size();i++){
            if(i>index && num[index]=='0') break;

            currNum=currNum*10 +(num[i]-'0');
            currStr+=num[i];

            if(index==0){
                expression(num,target,res,curr+currStr,sum+currNum,currNum,i+1);
            }
            else{
                expression(num,target,res, curr+'+'+currStr, sum+currNum, currNum, i+1);

                expression(num,target,res, curr+'-'+currStr, sum-currNum, -currNum, i+1);

                expression(num,target,res, curr+'*'+currStr, sum-prev + prev*currNum, prev*currNum ,i+1);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        vector<string>res;
        string curr="";
        expression(num,target,res,curr,0,0,0);
        return res;
    }
};
