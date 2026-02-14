#include<bits/stdc++.h>
using namespace std;

void min_platform_required(vector<float>&arrive,vector<float>&departure,int &min_platform){
    int n=arrive.size();
    int i=0;
    int j=0;
    int cnt=0;
    while(i<n && j<n){
        if(arrive[i]>departure[j]){
            cnt--;
            j++;
        }
        else if(arrive[i]<departure[j]){
            cnt++;
            i++;
        }
        min_platform=max(min_platform,cnt);
    }
}

int main(){
    vector<float>arrive={9.00,9.45,9.55,11.00,15.00,18.00};
    vector<float>departure={9.20,12.00,11.30,11.50,19.00,20.00};
    int min_platform=0;
    
    min_platform_required(arrive,departure,min_platform);
    cout<<"minimum number of platform required: "<<min_platform;
    return 0;
}
