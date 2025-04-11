#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(string& num,int& len){
    int r=len-1,l=len-1;
    ll shift=0;
    for(;r>=0;r--){
        l=min(r,l);
        bool moveleft=0;
        while(l>=0 && num[l]=='1'&& num[r]=='1'){
            l--;
            moveleft=1;
        }
        if(l>=0) {
            num[l]='1';
            num[r]='0';
        }
        if(moveleft) shift+=(r-l);
        if(num[r]=='0'){
            cout<<shift<<" ";
        }
        else cout<<-1<<" ";
    }
    cout<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string num;cin>>num;
        solve(num,n);
    }
    return 0;
}