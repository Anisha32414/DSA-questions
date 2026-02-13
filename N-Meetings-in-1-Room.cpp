#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int s;
    int e;
    int pos;
};

void n_meeting(vector<int>&start,vector<int>&end,vector<int>&ord,int &cnt){
    meeting meet[start.size()];
    for(int i=0;i<start.size();i++){
        meet[i].s=start[i];
        meet[i].e=end[i];
        meet[i].pos=i+1;
    }
    sort(meet,meet+start.size(),[](meeting a,meeting b){
       return a.e < b.e; 
    });
    
    int prev_meet=meet[0].e;
    ord.push_back(meet[0].pos);
    for(int i=1;i<start.size();i++){
        if(meet[i].s > prev_meet){
            cnt++;
            prev_meet=meet[i].e;
            ord.push_back(meet[i].pos);
        }
    }
}
int main(){
    
    vector<int>start={0,3,1,5,5,8};
    vector<int>end={5,4,2,9,7,9};
    vector<int>ord;
    int cnt=0;
    n_meeting(start,end,ord,cnt);
    
    cout<<"the order in which we will choose the meeting :";
    for(int i:ord) cout<<i<<" ";
    cout<<"\nmaximum no. of meetings possible in 1 room : "<<cnt;
    return 0;
}
