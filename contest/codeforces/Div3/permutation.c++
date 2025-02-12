#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n>1 && n<4) {cout<<"NO SOLUTION";return 0;}
    if(n==4) {cout<<"2 4 1 3"<<endl; return 0;}
    for(int i=n;i>0;i-=2){
        cout<<i<<" ";
    }
    for(int i=n-1;i>0;i-=2){
        cout<<i<<" ";
    }
    return 0;
}