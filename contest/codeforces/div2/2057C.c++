#include <bits/stdc++.h>
using namespace std;

#define ll long long
int d(int n){
    int c=0;
    while(n!=0){
        n=n>>1;
        c++;
    }
    return c;
}
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary = char((decimal % 2) + '0') + binary;
        decimal /= 2;
    }
    return binary.empty() ? "0" : binary;
}
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

int help(int n,int l,int r){
    string t=decimalToBinary(n);
    int find=INT_MIN;
    for(int i=0;i<t.length();i++){
        if(t[i]==)
    }
    

}

void solve(){
    int l,r;
    int a=r;

    // cin>>n>>k;
    // ll ele;
    // int res=0;
    // unordered_map<ll,int> m;
    // for(int i=0;i<n;i++){
    //     cin>>ele;
    //     m[ele]=m[ele]+1;
    //     if(m[ele]==1) res++;
    // }
    // vector<int> f;
    // for(auto it=m.begin();it!=m.end();it++){
    //     f.push_back(it->second);
    // }
    // sort(f.begin(),f.end());
    // for(int i=0;i<f.size() && f[i]<=k;i++){
    //     res=max(1,res-1);
    //     k=k-f[i];
    // }
    // cout<<res<<endl;
}

int main(){
    cout<<d(1<<4)<<endl;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}