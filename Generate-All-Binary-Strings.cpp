#include<bits/stdc++.h>
using namespace std;
void generate_binary_strings(int n,vector<string>&result,string &str,int count){
    if(count==n){
        result.push_back(str);
        return;
    }

    str.push_back('0');
    generate_binary_strings(n,result,str,count+1);
    str.pop_back();

    str.push_back('1');
    generate_binary_strings(n,result,str,count+1);
    str.pop_back();

}
int main(){
    int n;
    cout<<"enter the length of binary strings";
    cin>>n;
    vector<string>result;
    string str="";
    generate_binary_strings(n,result,str,0);
    cout<<endl<<"all binary strings :"<<endl;
    for(auto element:result){
        cout<<element<<" ";
    }
    return 0;
}
