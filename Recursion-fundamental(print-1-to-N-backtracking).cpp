//print 1 to N number 

#include <bits/stdc++.h>
using namespace std;

void printNum(int i,int n){
    if(i>n) return;
    cout<<i<<" ";
    printNum(i+1,n);
}
int main() {
    int n;
    cout<<"value of n : "<<endl;
    cin>>n;
    printNum(1,n);
    return 0;
}


//print N to 1 number
#include <bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n<=0) return;
    cout<<n<<" ";
    printNum(n-1);
}
int main() {
    int n;
    cout<<"value of n : "<<endl;
    cin>>n;
    printNum(n);
    return 0;
}


//print 1 to N no. using backtracking
#include <bits/stdc++.h>
using namespace std;

void printNum(int n){
    if(n<=0) return;
    printNum(n-1);
    cout<<n<<" ";
}
int main() {
    int n;
    cout<<"value of n : "<<endl;
    cin>>n;
    printNum(n);
    return 0;
}



//print n to 1 no. using backtracking
#include <bits/stdc++.h>
using namespace std;

void printNum(int i,int n){
    if(i>n) return;
    printNum(i+1,n);
    cout<<i<<" ";
}
int main() {
    int n;
    cout<<"value of n : "<<endl;
    cin>>n;
    printNum(1,n);
    return 0;
}
